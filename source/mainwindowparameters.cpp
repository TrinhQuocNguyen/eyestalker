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

void MainWindow::loadSettings(QString fileName)
{
    QSettings settings(fileName, QSettings::IniFormat);

    cameraAOIFractionHght                                       = settings.value("CamAOIHghtFraction",              cameraAOIFractionHght).toDouble();
    cameraAOIFractionWdth                                       = settings.value("CamAOIWdthFraction",              cameraAOIFractionWdth).toDouble();
    cameraAOIFractionXPos                                       = settings.value("CamAOIXPosFraction",              cameraAOIFractionXPos).toDouble();
    cameraAOIFractionYPos                                       = settings.value("CamAOIYPosFraction",              cameraAOIFractionYPos).toDouble();
    cameraFrameRateDesired                                      = settings.value("CameraFrameRateDesired",          cameraFrameRateDesired).toInt();
    cameraSubSamplingFactor                                     = settings.value("SubSamplingFactor",               1).toInt();
    dataDirectory                                               = settings.value("DataDirectory",                   "").toString().toStdString();
    dataFilename                                                = settings.value("DataFilename",                    "experiment_data").toString().toStdString();
    trialIndexOffline                                           = settings.value("trialIndexOffline",               0).toInt();
    imageTotalOffline                                           = settings.value("imageTotalOffline",               0).toInt();
    editSubjectName                                             = settings.value("SubjectName",                     "").toString();
    eyeAOIHghtFraction                                          = settings.value("AOIHghtFraction",                 eyeAOIHghtFraction).toDouble();
    eyeAOIWdthFraction                                          = settings.value("AOIWdthFraction",                 eyeAOIWdthFraction).toDouble();
    flashThreshold                                              = settings.value("FlashThreshold",                  230).toInt();
    GAIN_AUTO                                                   = settings.value("GainAuto",                        GAIN_AUTO).toBool();
    GAIN_BOOST                                                  = settings.value("GainBoost",                       GAIN_BOOST).toBool();
    mEyePropertiesParameters.alphaAverage                       = settings.value("AlphaAverage",                    0.005).toDouble();
    mEyePropertiesParameters.alphaMiscellaneous                 = settings.value("AlphaMiscellaneous",              0.75).toDouble();
    mEyePropertiesParameters.alphaMomentum                      = settings.value("AlphaMomentum",                   0.50).toDouble();
    mEyePropertiesParameters.alphaPrediction                    = settings.value("AlphaPrediction",                 0.75).toDouble();
    mEyePropertiesParameters.cannyBlurLevel                     = settings.value("CannyBlurLevel",                  4).toInt();
    mEyePropertiesParameters.cannyKernelSize                    = settings.value("CannyKernelSize",                 5).toInt();
    mEyePropertiesParameters.cannyLowerLimit                    = settings.value("CannyLowerLimit",                 300).toInt();
    mEyePropertiesParameters.cannyUpperLimit                    = settings.value("CannyUpperLimit",                 600).toInt();
    mEyePropertiesParameters.curvatureOffsetMin                 = settings.value("CurvatureOffset",                 5).toDouble();
    mEyePropertiesParameters.edgeIntensityOffset                = settings.value("EdgeIntensityOffset",             40).toDouble();
    mEyePropertiesParameters.edgeMaximumFitNumber               = settings.value("EdgeMaximumFitNumber",            3).toInt();
    mEyePropertiesParameters.ellipseFitErrorMaximum             = settings.value("EllipseFitErrorMaximum",          20).toDouble();
    mEyePropertiesParameters.glintSize                          = settings.value("GlintSize",                       12).toInt();
    mEyePropertiesParameters.circumferenceMax                   = settings.value("CircumferenceMax",                320).toDouble();
    mEyePropertiesParameters.circumferenceMin                   = settings.value("CircumferenceMin",                80).toDouble();
    mEyePropertiesParameters.aspectRatioMin                     = settings.value("AspectRatioMin",                  0.4).toDouble();
    mEyePropertiesParameters.pupilOffset                        = settings.value("PupilOffset",                     pupilOffsetIni).toInt();
    mEyePropertiesParameters.circumferenceChangeThreshold       = settings.value("CircumferenceChangeThreshold",    30.0).toDouble();
    mEyePropertiesParameters.aspectRatioChangeThreshold         = settings.value("AspectRatioChangeThreshold",      0.2).toDouble();
    Parameters::eyeAOIXPosFraction                              = settings.value("AOIXPosRelative",                 Parameters::eyeAOIXPosFraction).toDouble();
    Parameters::eyeAOIYPosFraction                              = settings.value("AOIYPosRelative",                 Parameters::eyeAOIYPosFraction).toDouble();
    Parameters::flashAOIHght                                    = settings.value("FlashAOIHght",                    100).toInt();
    Parameters::flashAOIWdth                                    = settings.value("FlashAOIWdth",                    60).toInt();
    Parameters::flashAOIXPos                                    = settings.value("FlashAOIXPos",                    227).toInt();
    Parameters::flashAOIYPos                                    = settings.value("FlashAOIYPos",                    500).toInt();
    SAVE_EYE_IMAGE                                              = settings.value("SaveEyeImage",                    true).toBool();
    subjectIdentifier                                           = settings.value("SubjectIdentifier",               "").toString();
    trialIndex                                                  = settings.value("TrialIndex",                      trialIndex).toInt();
    trialTimeLength                                             = settings.value("TrialTimeLength",                 trialTimeLength).toInt();

    if (mEyePropertiesParameters.pupilOffset < pupilOffsetMin) { mEyePropertiesParameters.pupilOffset = pupilOffsetIni; } // temporary solution

}

void MainWindow::saveSettings(QString fileName)
{
    QSettings settings(fileName, QSettings::IniFormat);

    settings.setValue("AlphaAverage",                   mEyePropertiesParameters.alphaAverage);
    settings.setValue("AlphaMiscellaneous",             mEyePropertiesParameters.alphaMiscellaneous);
    settings.setValue("AlphaMomentum",                  mEyePropertiesParameters.alphaMomentum);
    settings.setValue("AlphaPrediction",                mEyePropertiesParameters.alphaPrediction);
    settings.setValue("AOIHghtFraction",                eyeAOIHghtFraction);
    settings.setValue("AOIWdthFraction",                eyeAOIWdthFraction);
    settings.setValue("AOIXPosRelative",                Parameters::eyeAOIXPosFraction);
    settings.setValue("AOIYPosRelative",                Parameters::eyeAOIYPosFraction);
    settings.setValue("DataDirectory",                  QString::fromStdString(dataDirectory));
    settings.setValue("GainAuto",                       GAIN_AUTO);
    settings.setValue("GainBoost",                      GAIN_BOOST);
    settings.setValue("CamAOIHghtFraction",             cameraAOIFractionHght);
    settings.setValue("CamAOIWdthFraction",             cameraAOIFractionWdth);
    settings.setValue("CamAOIXPosFraction",             cameraAOIFractionXPos);
    settings.setValue("CamAOIYPosFraction",             cameraAOIFractionYPos);
    settings.setValue("CameraFrameRateDesired",         cameraFrameRateDesired);
    settings.setValue("CannyBlurLevel",                 mEyePropertiesParameters.cannyBlurLevel);
    settings.setValue("CannyKernelSize",                mEyePropertiesParameters.cannyKernelSize);
    settings.setValue("CannyLowerLimit",                mEyePropertiesParameters.cannyLowerLimit);
    settings.setValue("CannyUpperLimit",                mEyePropertiesParameters.cannyUpperLimit);
    settings.setValue("CircumferenceMax",               mEyePropertiesParameters.circumferenceMax);
    settings.setValue("CircumferenceMin",               mEyePropertiesParameters.circumferenceMin);
    settings.setValue("CurvatureOffset",                mEyePropertiesParameters.curvatureOffsetMin);
    settings.setValue("DataFilename",                   QString::fromStdString(dataFilename));
    settings.setValue("EdgeIntensityOffset",            mEyePropertiesParameters.edgeIntensityOffset);
    settings.setValue("EdgeMaximumFitNumber",           mEyePropertiesParameters.edgeMaximumFitNumber);
    settings.setValue("trialIndexOffline",              trialIndexOffline);
    settings.setValue("imageTotalOffline",              imageTotalOffline);
    settings.setValue("EllipseFitErrorMaximum",         mEyePropertiesParameters.ellipseFitErrorMaximum);
    settings.setValue("FlashAOIHght",                   Parameters::flashAOIHght);
    settings.setValue("FlashAOIWdth",                   Parameters::flashAOIWdth);
    settings.setValue("FlashAOIXPos",                   Parameters::flashAOIXPos);
    settings.setValue("FlashAOIYPos",                   Parameters::flashAOIYPos);
    settings.setValue("FlashThreshold",                 flashThreshold);
    settings.setValue("AspectRatioMin",                 mEyePropertiesParameters.aspectRatioMin);
    settings.setValue("GlintSize",                      mEyePropertiesParameters.glintSize);
    settings.setValue("PupilOffset",                    mEyePropertiesParameters.pupilOffset);
    settings.setValue("SaveEyeImage",                   SAVE_EYE_IMAGE);
    settings.setValue("SubjectName",                    subjectIdentifier);
    settings.setValue("SubSamplingFactor",              cameraSubSamplingFactor);
    settings.setValue("CircumferenceChangeThreshold",   mEyePropertiesParameters.circumferenceChangeThreshold);
    settings.setValue("AspectRatioChangeThreshold",     mEyePropertiesParameters.aspectRatioChangeThreshold);
    settings.setValue("TrialTimeLength",                TrialTimeLengthLineEdit->text().toInt());
}

void MainWindow::startRecordingManual()
{
    if (!FLASH_STANDBY) { startTrialRecording(); }
}

void MainWindow::setRealTimeEyeTracking(int state)
{
    if (state) { SAVE_EYE_IMAGE = false; }
    else       { SAVE_EYE_IMAGE = true;  }
}

void MainWindow::setFlashStandby(bool flag)
{
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);
    FLASH_STANDBY = flag;
}

void MainWindow::onFlashStandbySlider(int val)
{
    if (Parameters::CAMERA_RUNNING)
    {
        if (val == 0)
        {
            setFlashStandby(false);
            FlashStandbyLabel->setText("<font color='red'><b>OFF</b></font>");

            if (CameraHardwareGainAutoCheckBox->isChecked())
            {
                mUEyeOpencvCam.setAutoGain(true);
            }
        }
        else
        {
            dataFilename = (DataFilenameLineEdit->text()).toStdString();

            std::stringstream filename;
            filename << dataDirectory
                     << "/"
                     << dataFilename;

            if (boost::filesystem::exists(filename.str()))
            {
                QString text = "You are about to write data to the end of an existing file. Do you wish to continue?";
                ConfirmationWindow mConfirmationWindow(text);
                mConfirmationWindow.setWindowTitle("Please select option");

                if(mConfirmationWindow.exec() == QDialog::Rejected)
                {
                    FlashStandbySlider->setValue(0);
                    return;
                }
            }

            setFlashStandby(true);
            FlashStandbyLabel->setText("<font color='green'><b>ON</b></font>");

            if (CameraHardwareGainAutoCheckBox->isChecked())
            {
                mUEyeOpencvCam.setAutoGain(false);
            }
        }
    }
    else
    {
        FlashStandbySlider->setValue(0);
    }
}

void MainWindow::resetFlashMinIntensity()
{
    flashMinIntensity = 0;
    FlashThresholdSlider->setMinimum(0);
    FlashThresholdSlider->setValue(0);
}

void MainWindow::setPupilCircumference(double value)
{
    if (!Parameters::ONLINE_PROCESSING)
    {
        mEyePropertiesVariables.circumferencePrediction = value;
        PupilCircumferenceLabel->setText(QString::number(value, 'f', 1));
    }
}

void MainWindow::setPupilAspectRatio(double value)
{
    if (!Parameters::ONLINE_PROCESSING)
    {
        mEyePropertiesVariables.aspectRatioPrediction = value;
        PupilAspectRatioLabel->setText(QString::number(value, 'f', 2));
    }
}

void MainWindow::setEdgeIntensity(double value)
{
    if (!Parameters::ONLINE_PROCESSING)
    {
        mEyePropertiesVariables.edgeIntensityPrediction = value;
        EdgeIntensityLabel->setText(QString::number(value, 'f', 1));
    }
}

void MainWindow::setPupilCircumferenceMin(double value)
{
    if (mEyePropertiesParameters.circumferenceMax < value)
    {
        PupilCircumferenceMaxSlider->setDoubleValue(value);
    }

    mEyePropertiesParameters.circumferenceMin = value;
    PupilCircumferenceMinLabel->setText(QString::number(mEyePropertiesParameters.circumferenceMin, 'f', 1));
}

void MainWindow::setPupilCircumferenceMax(double value)
{
    if (mEyePropertiesParameters.circumferenceMin > value)
    {
        PupilCircumferenceMinSlider->setDoubleValue(value);
    }

    mEyePropertiesParameters.circumferenceMax = value;
    PupilCircumferenceMaxLabel->setText(QString::number(mEyePropertiesParameters.circumferenceMax, 'f', 1));
}

void MainWindow::setPupilAspectRatioMin(double value)
{
    mEyePropertiesParameters.aspectRatioMin = value;
    PupilAspectRatioSlider->setDoubleMinimum(mEyePropertiesParameters.aspectRatioMin);
    PupilAspectRatioMinLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::setEdgeIntensityOffset(double value)
{
    mEyePropertiesParameters.edgeIntensityOffset = value;
    EdgeIntensityOffsetLabel->setText(QString::number(value, 'f', 1));
}

void MainWindow::setCannyLowerLimit(int value)
{
    mEyePropertiesParameters.cannyLowerLimit = value;
    CannyLowerLimitLabel->setText(QString::number(value));
    CannyUpperLimitSlider->setRange(value, 4 * value);
}

void MainWindow::setCannyUpperLimit(int value)
{
    mEyePropertiesParameters.cannyUpperLimit = value;
    CannyUpperLimitLabel->setText(QString::number(value));
    CannyLowerLimitSlider->setMaximum(value);
}

void MainWindow::setCannyKernelSize(int value)
{
    int newValue = 2 * value - 1;
    mEyePropertiesParameters.cannyKernelSize = newValue;
    CannyKernelSizeLabel->setText(QString::number(newValue));
}

void MainWindow::setCannyBlurLevel(int value)
{
    mEyePropertiesParameters.cannyBlurLevel = value;
    CannyBlurLevelLabel->setText(QString::number(value));
}

void MainWindow::setAlphaAverage(double value)
{
    mEyePropertiesParameters.alphaAverage = value;
    AlphaAverageLabel->setText(QString::number(value, 'f', 3));
}

void MainWindow::setAlphaPrediction(double value)
{
    mEyePropertiesParameters.alphaPrediction = value;
    AlphaPredictionLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::setAlphaMiscellaneous(double value)
{
    mEyePropertiesParameters.alphaMiscellaneous = value;
    AlphaMiscellaneousLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::setAlphaMomentum(double value)
{
    mEyePropertiesParameters.alphaMomentum = value;
    AlphaMomentumLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::setThresholdCircumference(double value)
{
    mEyePropertiesParameters.circumferenceChangeThreshold = value;
    ThresholdCircumferenceLabel->setText(QString::number(value, 'f', 1));
}

void MainWindow::setThresholdAspectRatio(double value)
{
    mEyePropertiesParameters.aspectRatioChangeThreshold = value;
    ThresholdAspectRatioLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::setPupilHaarOffset(int value)
{
    mEyePropertiesParameters.pupilOffset = value;
    PupilHaarOffsetLabel->setText(QString::number(value));
}

void MainWindow::setGlintSize(int value)
{
    int newValue = 2 * value;
    mEyePropertiesParameters.glintSize = newValue;
    GlintSizeLabel->setText(QString::number(newValue));
}

void MainWindow::setCurvatureOffset(double value)
{
    mEyePropertiesParameters.curvatureOffsetMin = value;
    CurvatureOffsetLabel->setText(QString::number(value, 'f', 1));
}

void MainWindow::setEdgeMaximumFitNumber(int value)
{
    mEyePropertiesParameters.edgeMaximumFitNumber = value;
    EdgeMaximumFitNumberLabel->setText(QString::number(value));
}

void MainWindow::setEllipseFitErrorMaximum(double value)
{
    mEyePropertiesParameters.ellipseFitErrorMaximum = value;
    EllipseFitErrorMaximumLabel->setText(QString::number(value, 'f', 1));
}

void MainWindow::setCameraPixelClock(int value)
{
    cameraPixelClock = value;
    mUEyeOpencvCam.setPixelClock(cameraPixelClock);
    CameraPixelClockLabel->setText(QString::number(cameraPixelClock));

    // Set new frame rate

    std::vector<double> frameRateRange = mUEyeOpencvCam.getFrameRateRange();
    CameraFrameRateSlider->setDoubleRange(frameRateRange[0], frameRateRange[1]);
    CameraFrameRateSlider->setDoubleValue(frameRateRange[1]);
    setCameraFrameRate(frameRateRange[1]); // set frame-rate to maximum
}

void MainWindow::setCameraFrameRate(double value)
{
    cameraFrameRate = mUEyeOpencvCam.setFrameRate(value);
    CameraFrameRateLabel->setText(QString::number(cameraFrameRate, 'f', 1));

    // Set new exposure

    std::vector<double> exposureRange = mUEyeOpencvCam.getExposureRange();
    CameraExposureSlider->setDoubleRange(exposureRange[0], exposureRange[1]);
    CameraExposureSlider->setDoubleValue(exposureRange[1]);
    setCameraExposure(exposureRange[1]);
}

void MainWindow::setCameraExposure(double value)
{
    mUEyeOpencvCam.setExposure(value);
    CameraExposureLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::setCameraBlackLevelOffset(int value)
{
    double blackLevelOffset = mUEyeOpencvCam.setBlackLevelOffset(value);
    CameraBlackLevelOffsetLabel->setText(QString::number(blackLevelOffset));
}

void MainWindow::setCameraBlackLevelMode(int state)
{
    if (state) { mUEyeOpencvCam.setBlackLevelMode(true);  }
    else       { mUEyeOpencvCam.setBlackLevelMode(false); }
}

void MainWindow::setCameraGainBoost(int state)
{
    if (state) { mUEyeOpencvCam.setGainBoost(true);  }
    else       { mUEyeOpencvCam.setGainBoost(false); }
}

void MainWindow::setCameraAutoGain(int state)
{
    if (state)
    {
        GAIN_AUTO = true;
        mUEyeOpencvCam.setAutoGain(true);
    }
    else
    {
        GAIN_AUTO = false;
        mUEyeOpencvCam.setAutoGain(false);
    }
}

void MainWindow::setCameraHardwareGain(int val)
{
    if (!CameraHardwareGainAutoCheckBox->checkState())
    {
        mUEyeOpencvCam.setHardwareGain(val);
    }

    CameraHardwareGainLabel->setText(QString::number(val));
}

void MainWindow::setCameraSubSampling(int state)
{
    double subSamplingChange = 0;

    if (state == 1)
    {
        subSamplingChange = 0.5 * cameraSubSamplingFactor;
        cameraSubSamplingFactor = 2;
    }
    else if (state == 0)
    {
        subSamplingChange = cameraSubSamplingFactor;
        cameraSubSamplingFactor = 1;
    }

    cameraAOIWdthMax = cameraAOIWdthMax * subSamplingChange;
    cameraAOIHghtMax = cameraAOIHghtMax * subSamplingChange;

    ThresholdCircumferenceSlider->setDoubleValue(mEyePropertiesParameters.circumferenceChangeThreshold * subSamplingChange);

    updateCamAOIx();
    updateCamAOIy();

    if (Parameters::CAMERA_RUNNING)
    {
        if (mUEyeOpencvCam.freeImageMemory())
        {
            if (mUEyeOpencvCam.setSubSampling(cameraSubSamplingFactor))
            {
                if (mUEyeOpencvCam.allocateMemory(Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
                {
                    mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght);
                    Parameters::CAMERA_READY = true;
                }
            }
        }

        getCameraParameters();
    }
}

void MainWindow::cropAOI()
{
    int absXPos = Parameters::eyeAOIXPos + Parameters::cameraAOIXPos;
    int absYPos = Parameters::eyeAOIYPos + Parameters::cameraAOIYPos;

    double fracXPos = absXPos / (double) cameraAOIWdthMax;
    double fracYPos = absYPos / (double) cameraAOIHghtMax;
    double fracWdth = (Parameters::eyeAOIWdth - cameraAOIWdthMin) / (double) (cameraAOIWdthMax - cameraAOIWdthMin);
    double fracHght = (Parameters::eyeAOIHght - cameraAOIHghtMin) / (double) (cameraAOIHghtMax - cameraAOIHghtMin);

    Parameters::eyeAOIXPosFraction = 1.0;
    Parameters::eyeAOIYPosFraction = 1.0;
    eyeAOIWdthFraction = 1.0;
    eyeAOIHghtFraction = 1.0;

    CamEyeAOIXPosSlider->setDoubleValue(fracXPos);
    CamEyeAOIYPosSlider->setDoubleValue(fracYPos);
    CamEyeAOIWdthSlider->setDoubleValue(fracWdth);
    CamEyeAOIHghtSlider->setDoubleValue(fracHght);
}

void MainWindow::updateCamAOIx()
{
    Parameters::cameraAOIWdth = floor(((cameraAOIWdthMax - cameraAOIWdthMin) * cameraAOIFractionWdth + cameraAOIWdthMin) / (double) cameraAOIWdthStepSize) * cameraAOIWdthStepSize;
    Parameters::cameraAOIXPos = floor((cameraAOIWdthMax * cameraAOIFractionXPos) / (double) cameraAOIWdthStepSize) * cameraAOIWdthStepSize;
    CamEyeAOIXPosSlider->setDoubleMaximum((cameraAOIWdthMax - Parameters::cameraAOIWdth) / (double) cameraAOIWdthMax);
    updateEyeAOIx();
}

void MainWindow::updateCamAOIy()
{
    Parameters::cameraAOIHght = floor(((cameraAOIHghtMax - cameraAOIHghtMin) * cameraAOIFractionHght + cameraAOIHghtMin) / (double) cameraAOIHghtStepSize) * cameraAOIHghtStepSize;
    Parameters::cameraAOIYPos = floor((cameraAOIHghtMax * cameraAOIFractionYPos) / (double) cameraAOIHghtStepSize) * cameraAOIHghtStepSize;
    CamEyeAOIYPosSlider->setDoubleMaximum((cameraAOIHghtMax - Parameters::cameraAOIHght) / (double) cameraAOIHghtMax);
    updateEyeAOIy();
}

void MainWindow::updateEyeAOIx()
{
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

    Parameters::eyeAOIWdth = round(Parameters::cameraAOIWdth * eyeAOIWdthFraction);
    Parameters::eyeAOIXPos = round(Parameters::cameraAOIWdth * Parameters::eyeAOIXPosFraction);

    if (Parameters::eyeAOIXPos + Parameters::eyeAOIWdth > Parameters::cameraAOIWdth)
    {
        Parameters::eyeAOIXPos = Parameters::cameraAOIWdth - Parameters::eyeAOIWdth;
    }
}

void MainWindow::updateEyeAOIy()
{    
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

    Parameters::eyeAOIHght = round(Parameters::cameraAOIHght * eyeAOIHghtFraction);
    Parameters::eyeAOIYPos = round(Parameters::cameraAOIHght * Parameters::eyeAOIYPosFraction);

    if (Parameters::eyeAOIYPos + Parameters::eyeAOIHght > Parameters::cameraAOIHght)
    {
        Parameters::eyeAOIYPos = Parameters::cameraAOIHght - Parameters::eyeAOIHght;
    }
}

void MainWindow::setCamEyeAOIWdth(double fraction)
{
    cameraAOIFractionWdth = fraction;

    Parameters::cameraAOIWdth = floor(((cameraAOIWdthMax - cameraAOIWdthMin) * cameraAOIFractionWdth + cameraAOIWdthMin) / (double) cameraAOIWdthStepSize) * cameraAOIWdthStepSize;

    updateEyeAOIx();

    if (mUEyeOpencvCam.freeImageMemory())
    {
        if (mUEyeOpencvCam.allocateMemory(Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
        {
            if (Parameters::cameraAOIXPos + Parameters::cameraAOIWdth <= cameraAOIWdthMax)
            {
                if (mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
                {
                    Parameters::CAMERA_READY = true;
                    getCameraParameters();
                }
            }
        }
    }

    CamEyeAOIXPosSlider->setDoubleMaximum((cameraAOIWdthMax - Parameters::cameraAOIWdth) / (double) cameraAOIWdthMax);
}

void MainWindow::setCamEyeAOIHght(double fraction)
{
    cameraAOIFractionHght = fraction;

    Parameters::cameraAOIHght = floor(((cameraAOIHghtMax - cameraAOIHghtMin) * cameraAOIFractionHght + cameraAOIHghtMin) / (double) cameraAOIHghtStepSize) * cameraAOIHghtStepSize;

    updateEyeAOIy();

    if (mUEyeOpencvCam.freeImageMemory())
    {
        if (mUEyeOpencvCam.allocateMemory(Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
        {
            if (Parameters::cameraAOIYPos + Parameters::cameraAOIHght <= cameraAOIHghtMax)
            {
                if (mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
                {
                    Parameters::CAMERA_READY = true;
                    getCameraParameters();
                }
            }
        }
    }

    CamEyeAOIYPosSlider->setDoubleMaximum((cameraAOIHghtMax - Parameters::cameraAOIHght) / (double) cameraAOIHghtMax);
}

void MainWindow::setCamEyeAOIXPos(double fraction)
{
    cameraAOIFractionXPos = fraction;

    Parameters::cameraAOIXPos = floor((cameraAOIWdthMax * cameraAOIFractionXPos) / (double) cameraAOIWdthStepSize) * cameraAOIWdthStepSize;

    if (mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
    {
        Parameters::CAMERA_READY = true;
        getCameraParameters();
    }
}

void MainWindow::setCamEyeAOIYPos(double fraction)
{
    cameraAOIFractionYPos = fraction;

    Parameters::cameraAOIYPos = floor((cameraAOIHghtMax * cameraAOIFractionYPos) / (double) cameraAOIHghtStepSize) * cameraAOIHghtStepSize;

    if (mUEyeOpencvCam.setAOI(Parameters::cameraAOIXPos, Parameters::cameraAOIYPos, Parameters::cameraAOIWdth, Parameters::cameraAOIHght))
    {
        Parameters::CAMERA_READY = true;
        getCameraParameters();
    }
}

void MainWindow::setEyeROIWdth(double fraction)
{
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

    eyeAOIWdthFraction = fraction;

    Parameters::eyeAOIWdth = round(Parameters::cameraAOIWdth * eyeAOIWdthFraction);

    if (Parameters::eyeAOIXPos + Parameters::eyeAOIWdth > Parameters::cameraAOIWdth)
    {
        Parameters::eyeAOIXPos = Parameters::cameraAOIWdth - Parameters::eyeAOIWdth;
    }
}

void MainWindow::setEyeROIHght(double fraction)
{
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

    eyeAOIHghtFraction = fraction;

    Parameters::eyeAOIHght = round(Parameters::cameraAOIHght * eyeAOIHghtFraction);

    if (Parameters::eyeAOIYPos + Parameters::eyeAOIHght > Parameters::cameraAOIHght)
    {
        Parameters::eyeAOIYPos = Parameters::cameraAOIHght - Parameters::eyeAOIHght;
    }
}

void MainWindow::setFlashAOIXPos(int val)
{
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

    Parameters::flashAOIXPos = val;
    CamQImage->setFlashAOI(Parameters::flashAOIXPos, Parameters::flashAOIYPos, Parameters::flashAOIWdth, Parameters::flashAOIHght);
}

void MainWindow::setFlashAOIYPos(int val)
{
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

    Parameters::flashAOIYPos = val;
    CamQImage->setFlashAOI(Parameters::flashAOIXPos, Parameters::flashAOIYPos, Parameters::flashAOIWdth, Parameters::flashAOIHght);
}

void MainWindow::setFlashAOIWdth(int val)
{
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

    Parameters::flashAOIWdth = val;
    CamQImage->setFlashAOI(Parameters::flashAOIXPos, Parameters::flashAOIYPos, Parameters::flashAOIWdth, Parameters::flashAOIHght);
}

void MainWindow::setFlashAOIHght(int val)
{
    std::lock_guard<std::mutex> primaryMutexLock(Parameters::primaryMutex);

    Parameters::flashAOIHght = val;
    CamQImage->setFlashAOI(Parameters::flashAOIXPos, Parameters::flashAOIYPos, Parameters::flashAOIWdth, Parameters::flashAOIHght);
}

void MainWindow::setFlashThreshold(int val)
{
    flashThreshold = val;
    FlashThresholdLabel->setText(QString::number(flashThreshold));
}

void MainWindow::setTrialIndex(int val)
{
    trialIndex = val;
}

void MainWindow::setAOILeftEye()
{
    CamEyeAOIXPosSlider->setDoubleValue(cameraAOIFractionXPosDefaultLeft);
    CamEyeAOIYPosSlider->setDoubleValue(cameraAOIFractionYPosDefaultLeft);
    CamEyeAOIWdthSlider->setDoubleValue(cameraAOIFractionWdthDefaultLeft);
    CamEyeAOIHghtSlider->setDoubleValue(cameraAOIFractionHghtDefaultLeft);
}

void MainWindow::setAOIRghtEye()
{
    CamEyeAOIXPosSlider->setDoubleValue(cameraAOIFractionXPosDefaultRght);
    CamEyeAOIYPosSlider->setDoubleValue(cameraAOIFractionYPosDefaultRght);
    CamEyeAOIWdthSlider->setDoubleValue(cameraAOIFractionWdthDefaultRght);
    CamEyeAOIHghtSlider->setDoubleValue(cameraAOIFractionHghtDefaultRght);
}

void MainWindow::setDrawHaar(int state)
{
    if (state) { Parameters::drawFlags.haar = true;  }
    else       { Parameters::drawFlags.haar = false; }
}

void MainWindow::setDrawEdge(int state)
{
    if (state) { Parameters::drawFlags.edge = true;  }
    else       { Parameters::drawFlags.edge = false; }
}

void MainWindow::setDrawElps(int state)
{
    if (state) { Parameters::drawFlags.elps = true;  }
    else       { Parameters::drawFlags.elps = false; }
}
