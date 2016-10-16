//  Copyright (C) 2016  Terence Brouns

//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>

#include "headers/mainwindow.h"

void MainWindow::startReviewSession()
{
    editImageIndex = 0;

    Parameters::REALTIME_PROCESSING = false; // turn off pupil tracking

    { // unlock frame grabbing threads
        std::unique_lock<std::mutex> frameCaptureMutexLock(Parameters::frameCaptureMutex);
        Parameters::frameCaptureCV.notify_all(); // unlock getFrame() thread
    }

    { // wait for threads to finish
        std::unique_lock<std::mutex> lck(mtx);
        while (Parameters::CAMERA_RUNNING) cv.wait(lck);
    }

    // hide camera AOI sliders
    CamEyeAOIWdthSlider->setVisible(false);
    CamEyeAOIHghtSlider->setVisible(false);
    CamEyeAOIXPosSlider->setVisible(false);
    CamEyeAOIYPosSlider->setVisible(false);

    EyeTrackingReviewWidget->setVisible(true);

    CamQImage->clearImage();
    EyeQImage->clearImage();

    // hide tab with camera parameters
    EyeTrackingParameterTabWidget->removeTab(0);

    updateReviewImages(0);
}

void MainWindow::loadReviewSession()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Please select an info.ini file"), QString::fromStdString(dataDirectory), tr("Ini file (*.ini)"));

    if (!fileName.isEmpty())
    {
        int prevSubSampling = cameraSubSamplingFactor;

        loadSettings(fileName);

        int nextSubSampling = cameraSubSamplingFactor;
        cameraSubSamplingFactor = prevSubSampling;
        setCameraSubSampling(nextSubSampling - 1);

        editDataDirectory = QFileInfo(fileName).absolutePath();

        updateReviewSession();
        updateReviewImages(0);

        std::stringstream directoryName;
        directoryName << editDataDirectory.toStdString() << "/processed";

        if (!boost::filesystem::exists(directoryName.str()))
        {
            mkdir(directoryName.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        }

        // count number of trials

        editDataTotal = 0;

        while (true)
        {
            std::stringstream folderName;
            folderName << editDataDirectory.toStdString() << "/../trial_" << editDataTotal;

            if (!boost::filesystem::exists(folderName.str()))
            {
                break;
            }

            editDataTotal++;
        }

        ReviewTrialSlider->setMaximum(editDataTotal);
        ReviewTrialSpinBox->setMaximum(editDataTotal);

        // get time stamps

        if (timeVector.empty())
        {
            // Grab time stamps

            double times[editImageTotal + 2][editDataTotal];

            std::stringstream filename;
            filename << editDataDirectory.toStdString()
                     << "/../timestamps.dat";

            std::ifstream data;
            data.open(filename.str().c_str());

            if (data.is_open())
            {
                for (int j = 0; j < editImageTotal + 2; j++)
                {
                    for (int i = 0; i < editDataTotal; i++)
                    {
                        data >> times[j][i];
                        timeVector.push_back(times[j][i]);
                    }
                }
            }
        }
    }
}

void MainWindow::changeReviewSession(int index)
{
    QString infoFilePath = editDataDirectory;

    int numOfDigits;

    if (editDataIndex != 0)
    {
        numOfDigits = floor(log10(editDataIndex)) + 1;
    }
    else
    {
        numOfDigits = 1;
    }

    infoFilePath.replace(infoFilePath.size() - numOfDigits, numOfDigits, QString::number(index - 1)); // replace last character(s)

    QString infoFileDataDirectory = infoFilePath;
    infoFilePath.append("/info.ini");

    if (boost::filesystem::exists(infoFilePath.toStdString()))
    {
        loadSettings(infoFilePath);
        editDataIndex = index - 1;
        editDataDirectory = infoFileDataDirectory;

        updateReviewSession();
        updateReviewImages(0);
    }
}

void MainWindow::updateReviewSession()
{
    if (editImageTotal > 0)
    {
        setParameterWidgets();

        vEyePropertiesVariables.resize(editImageTotal + 1);
        vEyePropertiesVariables[0] = mEyePropertiesVariables;

        editImageIndex = 0;

        ReviewImageSlider->setValue(0);
        ReviewImageSlider->setMaximum(editImageTotal - 1);

        // Create folder

        std::stringstream directoryName;
        directoryName << editDataDirectory.toStdString() << "/processed/";

        if (!boost::filesystem::exists(directoryName.str()))
        {
            mkdir(directoryName.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        }
    }
}

void MainWindow::setPupilPosition(double xPos, double yPos)
{
    std::lock_guard<std::mutex> secondaryMutexLock(Parameters::secondaryMutex);

    if (xPos > 0 && xPos < Parameters::eyeAOIWdth && yPos > 0 && yPos < Parameters::eyeAOIHght)
    {
        int pupilHaarWdth = round(mEyePropertiesVariables.pupilCircumference / M_PI);
        int pupilHaarWdthOffset = pupilHaarWdth + round(pupilHaarWdth * mEyePropertiesParameters.pupilOffset * 2);

        mEyePropertiesVariables.searchRadius = ceil(0.5 * pupilHaarWdthOffset);
        mEyePropertiesVariables.xPosPredicted = xPos;
        mEyePropertiesVariables.yPosPredicted = yPos;

        if (editImageIndex == 0)
        {
            mEyePropertiesVariables.xPos = xPos;
            mEyePropertiesVariables.yPos = yPos;
        }
    }
}

void MainWindow::updateReviewImages(int imgIndex)
{
    if (editImageTotal > 0)
    {
        std::stringstream ss;
        ss << "<b>" << imgIndex + 1 << " / " << editImageTotal << "</b>";
        QString title = QString::fromStdString(ss.str());
        ReviewImageFrameTextBox->setText(title);

        // Raw

        std::stringstream fileNameRaw;
        fileNameRaw << editDataDirectory.toStdString()
                    << "/raw/" << imgIndex << ".png";

        if (boost::filesystem::exists(fileNameRaw.str()))
        {
            cv::Mat rawEyeImage = cv::imread(fileNameRaw.str(), CV_LOAD_IMAGE_COLOR);

            CamQImage->loadImage(rawEyeImage);
            CamQImage->setEyeAOI(Parameters::eyeAOIXPos, Parameters::eyeAOIYPos, Parameters::eyeAOIWdth, Parameters::eyeAOIHght);
            CamQImage->setImage();
        }
        else
        {
            CamQImage->clearImage();
        }

        std::stringstream fileName;
        fileName << editDataDirectory.toStdString()
                 << "/processed/" << imgIndex << ".png";

        if (boost::filesystem::exists(fileName.str()))
        {
            cv::Mat eyeImage = cv::imread(fileName.str(), CV_LOAD_IMAGE_COLOR);

            EyeQImage->loadImage(eyeImage);
            EyeQImage->setImage();
        }
        else
        {
            EyeQImage->clearImage();
        }
    }
    else
    {
        CamQImage->clearImage();
        EyeQImage->clearImage();

        ReviewImageFrameTextBox->setText("<b>0 / 0</b>");
    }
}

void MainWindow::updateRawImage() // for signal from qimageopencv
{
    std::stringstream fileNameRaw;
    fileNameRaw << editDataDirectory.toStdString()
                << "/raw/" << editImageIndex << ".png";

    if (boost::filesystem::exists(fileNameRaw.str()))
    {
        cv::Mat rawEyeImage = cv::imread(fileNameRaw.str(), CV_LOAD_IMAGE_COLOR);

        CamQImage->loadImage(rawEyeImage);
        CamQImage->setEyeAOI(Parameters::eyeAOIXPos, Parameters::eyeAOIYPos, Parameters::eyeAOIWdth, Parameters::eyeAOIHght);
        CamQImage->setImage();
    }
    else
    {
        CamQImage->clearImage();
    }
}

void MainWindow::prevReviewImage()
{
    if (editImageIndex > 0)
    {
        editImageIndex--;
        ReviewImageSlider->setValue(editImageIndex);
    }
}

void MainWindow::nextReviewImage()
{
    if (editImageIndex < editImageTotal - 1)
    {
        editImageIndex++;
        ReviewImageSlider->setValue(editImageIndex);
    }
}

void MainWindow::setReviewImageFrame(int frame)
{
    if (!PROCESSING_ALL_IMAGES)
    {
        editImageIndex = frame;
        mEyePropertiesVariables = vEyePropertiesVariables[editImageIndex];
        setVariableWidgets(mEyePropertiesVariables);
        updateReviewImages(editImageIndex);
    }
}

void MainWindow::reviewPupilDetectionOneFrame()
{
    cv::Mat rawEyeImage;

    std::stringstream fileNameRaw;
    fileNameRaw << editDataDirectory.toStdString()
                << "/raw/" << editImageIndex << ".png";

    if (boost::filesystem::exists(fileNameRaw.str()))
    {
        rawEyeImage = cv::imread(fileNameRaw.str(), CV_LOAD_IMAGE_COLOR);
    }
    else
    {
        return;
    }

    eyeProperties mEyePropertiesTemp;

    int eyeAOIXPosTemp;
    int eyeAOIYPosTemp;

    int eyeAOIWdthTemp;
    int eyeAOIHghtTemp;

    {
        std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

        mEyePropertiesTemp.v = mEyePropertiesVariables;
        mEyePropertiesTemp.p = mEyePropertiesParameters;

        eyeAOIXPosTemp = Parameters::eyeAOIXPos;
        eyeAOIYPosTemp = Parameters::eyeAOIYPos;

        eyeAOIWdthTemp = Parameters::eyeAOIWdth;
        eyeAOIHghtTemp = Parameters::eyeAOIHght;
    }

    // Grab raw images

    // Pupil tracking algorithm

    cv::Rect eyeRegion(eyeAOIXPosTemp, eyeAOIYPosTemp, eyeAOIWdthTemp, eyeAOIHghtTemp);
    eyeProperties mEyePropertiesNew = pupilDetector(rawEyeImage(eyeRegion), mEyePropertiesTemp);

    // Save processed images

    cv::Mat imageEye = mEyePropertiesNew.m.image.clone();
    drawAll(imageEye, mEyePropertiesNew);

    std::stringstream filename;
    filename << editDataDirectory.toStdString()
             << "/processed/" << editImageIndex << ".png";

    cv::imwrite(filename.str(), imageEye);

    // Get pupil coords in screen coords

    mEyePropertiesNew.v.xPosAbs = mEyePropertiesNew.v.xPos + eyeAOIXPosTemp;
    mEyePropertiesNew.v.yPosAbs = mEyePropertiesNew.v.yPos + eyeAOIYPosTemp;

    // Record pupil positions

    {
        std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

        vEyePropertiesVariables[editImageIndex + 1] = mEyePropertiesNew.v;
        mEyePropertiesMiscellaneous = mEyePropertiesNew.m;
    }
}

void MainWindow::detectPupilOneFrame()
{
    reviewPupilDetectionOneFrame();
    updateReviewImages(editImageIndex);
}

void MainWindow::detectPupilAllFrames()
{
    if (!PROCESSING_ALL_IMAGES)
    {
        PROCESSING_ALL_IMAGES = true;

        std::thread pupilDetectionThread(&MainWindow::reviewPupilDetectionAllFrames, this);
        pupilDetectionThread.detach();

        while (PROCESSING_ALL_IMAGES)
        {
            ReviewImageSlider->setValue(editImageIndex);

            std::stringstream ss;
            ss << "<b>" << editImageIndex + 1 << " / " << editImageTotal << "</b>";
            QString title = QString::fromStdString(ss.str());
            ReviewImageFrameTextBox->setText(title);

            msWait(1000 / guiUpdateFrequency);
        }
    }
    else
    {
        PROCESSING_ALL_IMAGES = false;
    }
}

void MainWindow::reviewPupilDetectionAllFrames()
{
    int initialIndex = editImageIndex; // needed for progressbar

    for (editImageIndex = initialIndex; editImageIndex < editImageTotal && PROCESSING_ALL_IMAGES; editImageIndex++)
    {
        mEyePropertiesVariables = vEyePropertiesVariables[editImageIndex];
        reviewPupilDetectionOneFrame();
    }

    if (PROCESSING_ALL_IMAGES)
    {
        ReviewImageSlider->setValue(editImageIndex);
        reviewSaveExperimentData();
        PROCESSING_ALL_IMAGES = false;
    }
}

void MainWindow::detectPupilAllTrials()
{
    if (!PROCESSING_ALL_TRIALS)
    {
        PROCESSING_ALL_TRIALS = true;

        for (int i = editDataIndex; i < editDataTotal && PROCESSING_ALL_TRIALS; i++)
        {
            ReviewTrialSlider->setValue(i + 1);
            detectPupilAllFrames();
        }
    }

    PROCESSING_ALL_IMAGES = false;
    PROCESSING_ALL_TRIALS = false;
}

void MainWindow::onSavePupilData()
{
    reviewSaveExperimentData();
}

void MainWindow::reviewSaveExperimentData()
{
    // save data

    std::stringstream filename;
    filename << editDataDirectory.toStdString()
             << "/tracking_data.dat";

    std::ofstream file;
    file.open(filename.str());

    file << std::setw(3) << std::setfill('0') << timeVector[editDataIndex * (editImageTotal + 2)] << ";"; // print with leading zeros
    file << (int) timeVector[editDataIndex * (editImageTotal + 2) + 1] << ";"; // time of day in milliseconds

    file << std::fixed;
    file << std::setprecision(3);

    eyeXPositions.resize(editImageTotal);
    eyeYPositions.resize(editImageTotal);
    eyeDetectionFlags.resize(editImageTotal);
    timeStamps.resize(editImageTotal);

    for (int i = 0; i < editImageTotal; i++)
    {
        eyeXPositions[i] = vEyePropertiesVariables[i + 1].xPosAbs;
        eyeYPositions[i] = vEyePropertiesVariables[i + 1].yPosAbs;
        eyeDetectionFlags[i] = vEyePropertiesVariables[i + 1].pupilDetected;
        timeStamps[i] = timeVector[i + editDataIndex * (editImageTotal + 2) + 2];
    }

    writeToFile(file, eyeDetectionFlags, timeStamps);
    writeToFile(file, eyeDetectionFlags, eyeXPositions);
    writeToFile(file, eyeDetectionFlags, eyeYPositions);

    file.close();
}




