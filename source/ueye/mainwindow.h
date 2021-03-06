//  EyeStalker: robust video-based eye tracking
//  Copyright (C) 2016  Terence Brouns, t.s.n.brouns@gmail.com

//  EyeStalker is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  EyeStalker is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Files

#include "../confirmationwindow.h"
#include "../constants.h"
#include "../drawfunctions.h"
#include "../eyestalker.h"
#include "../parameters.h"
#include "../parameterwidget.h"
#include "../sliderdouble.h"
#include "../structures.h"
#include "../qimageopencv.h"
#include "../variablewidget.h"

#include "qwtplotwidget.h"
#include "ueyeopencv.h"

// Standard Template

#include <chrono>
#include <condition_variable> // std::condition_variable
#include <ctime>        // for current date
#include <fstream>      // std::ofstream
#include <iomanip>
#include <iostream>     // std::ofstream
#include <thread>

// Directory creation

#include <sys/types.h>
#include <sys/stat.h>

// Boost

#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/range/iterator_range.hpp>

// OpenCV

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// uEye

#include <ueye.h>

// QT

#include <QAction>
#include <QApplication>
#include <QCheckBox>
#include <QColor>
#include <QDebug>
#include <QDesktopWidget>
#include <QDoubleSpinBox>
#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QRect>
#include <QScrollArea>
#include <QSettings>
#include <QSize>
#include <QSlider>
#include <QSpinBox>
#include <QTabWidget>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    bool APP_EXIT;
    bool APP_RUNNING;
    bool TRIAL_RECORDING;
    bool FLASH_STANDBY;
    bool OFFLINE_SAVE_DATA;
    bool PROCESSING_ALL_IMAGES;
    bool PROCESSING_ALL_TRIALS;
    bool PROCESSING_ALL_EXPS;

    bool SET_FRAME_RATE;

    char currentDate[80];

    AOIPropertiesDouble camAOIRatioLeft;
    AOIPropertiesDouble camAOIRatioRght;
    AOIPropertiesDouble camAOIRatio;

    AOIProperties flashAOI;
    AOIProperties flashAOILeft;
    AOIProperties flashAOIRght;

    double flashDetection(const cv::Mat&);

    double cameraFrameRate;
    double frameRateOffset;
    double flashMinIntensity;
    double guiUpdateFrequency; // refresh frequency of GUI (in Hz)
    double relativeTime;       // in ms
    std::vector<std::vector<double>> timeMatrix;
    int cameraAOIHghtMax;
    int cameraAOIHghtMin;
    int cameraAOIHghtStepSize;
    int cameraAOIWdthMax;
    int cameraAOIWdthMin;
    int cameraAOIWdthStepSize;
    int cameraSubSamplingFactor;
    int camImageHght;
    int camImageWdth;
    int cameraFrameRateDesired;
    int cameraPixelClock;
    int trialIndexOffline;
    int trialTotalOffline;
    int imageIndexOffline;
    int imageTotalOffline;
    int eyeAOIHghtMin;
    int eyeAOIWdthMin;
    int eyeImageHght;
    int eyeImageWdth;
    int flashThreshold;
    double flashThresholdMin;
    int frameCount;
    int getCurrentTime();
    int trialFrameTotal;
    int trialIndex;
    int trialStartTime;
    int trialTimeLength;

    QImageOpenCV *CamQImage;
    QLabel *CameraBlackLevelOffsetLabel;
    QLabel *CameraExposureLabel;
    QLabel *CameraFrameRateLabel;
    QLabel *CameraHardwareGainLabel;
    QLabel *CameraPixelClockLabel;
    QLabel *DataAnalysisTitleTextBox;
    QLabel *DataDirectoryTextBox;
    QLabel *FlashStandbyLabel;
    QLabel *FlashThresholdLabel;
    QLabel *OfflineImageFrameTextBox;
    QLineEdit *DataFilenameLineEdit;
    QLineEdit *TrialTimeLengthLineEdit;

    QSlider *CameraBlackLevelOffsetSlider;
    QSlider *CameraHardwareGainSlider;
    QSlider *CameraPixelClockSlider;
    QSlider *ExperimentEyeVideoSlider;
    QSlider *FlashThresholdSlider;
    QSlider *FlashStandbySlider;
    QSlider *OfflineImageSlider;
    QSlider *OfflineTrialSlider;
    QSpinBox *CameraFrameRateDesiredSpinBox;
    QSpinBox *OfflineTrialSpinBox;
    QSpinBox *TrialIndexSpinBox;
    QString dataDirectoryOffline;

    QString LastUsedSettingsFileName;
    QTabWidget *MainTabWidget;
    QTimer *UpdateCameraImageTimer;

    std::condition_variable cv;
    std::condition_variable saveConditionVariable;
    std::condition_variable cvOffline;

    std::mutex mutexAOI_1;
    std::mutex mutexAOI_2;
    std::mutex mutexQuit;
    std::mutex mutexOffline;

    std::string dataDirectory;
    std::string dataFilename;

    // Qwt plotting

    QwtPlotWidget* mQwtPlotWidget;

    // Options menu

    QCheckBox* BeadDetectionCheckBox;
    QCheckBox *OnlineProcessingCheckBox;

    // Interface

    QScrollArea *BeadTrackingScrollArea;
    QScrollArea *AdvancedScrollArea;

    // AOIs

    AOIProperties camAOITemp;

    QWidget* AOIEyeOptionsWidget;

    SliderDouble *CamAOIHghtSlider;
    SliderDouble *CamAOIWdthSlider;
    SliderDouble *CamAOIXPosSlider;
    SliderDouble *CamAOIYPosSlider;

    SliderDouble *EyeAOIHghtSlider;
    SliderDouble *EyeAOIWdthSlider;

    SliderDouble *BeadAOIHghtSlider;
    SliderDouble *BeadAOIWdthSlider;

    void updateCamAOIx();
    void updateCamAOIy();
    void updateAOIx();
    void updateAOIy();

    // AOI Flash

    bool checkFlashAOI(AOIProperties&, const AOIProperties&, const AOIProperties&);

    // Camera interface

    QCheckBox *CameraHardwareGainAutoCheckBox;
    QCheckBox *CameraHardwareGainBoostCheckBox;

    SliderDouble *CameraExposureSlider;
    SliderDouble *CameraFrameRateSlider;

    // Camera functions and variables

    cv::Mat imageCamera;

    UEyeOpencvCam mUEyeOpencvCam;

    void findCamera();
    void getCameraParameters();

    // Variables and parameters

    void resetVariablesHard(detectionVariables&, const detectionParameters&, const AOIProperties&);
    void resetVariablesSoft(detectionVariables&, const detectionParameters&, const AOIProperties&);

    detectionVariables mDetectionVariablesBead;
    detectionVariables mDetectionVariablesEye;

    std::vector<detectionVariables> vDetectionVariablesBead;
    std::vector<detectionVariables> vDetectionVariablesEye;

    std::vector<dataVariables> vDataVariablesEye;
    std::vector<dataVariables> vDataVariablesBead;

    drawVariables mDrawVariablesEye;
    dataVariables mDataVariablesEye;

    drawVariables mDrawVariablesBead;
    dataVariables mDataVariablesBead;

    ParameterWidget *mParameterWidgetBead;
    ParameterWidget *mParameterWidgetEye;

    VariableWidget *mVariableWidgetEye;
    VariableWidget *mVariableWidgetBead;

    // Saving and loading settings

    detectionParameters loadParameters(QString, QString, std::vector<double> parameters);
    void saveParameters(QString, QString, detectionParameters);
    void loadSettings(QString);
    void saveSettings(QString);

    // Threads

    void pupilTracking();

    // Experimental

    bool SAVE_ASPECT_RATIO;
    bool SAVE_CIRCUMFERENCE;
    bool SAVE_POSITION;
    bool SAVE_EYE_IMAGE;

    unsigned long long absoluteTime; // in units of 0.1 microseconds
    unsigned long long startTime;

    void startTrialRecording();
    void saveTrialData();

    // Offline interface

    QWidget *OfflineModeWidget;

    // Offline functions and variables

    void countNumTrials();
    void countNumImages();

    void setupOfflineSession();
    void updateOfflineTrial();

    void detectCurrentFrame(int);
    void detectAllFrames();

    void setCurvatureMeasurement(detectionParameters&, int);

    // Advanced

    developmentOptions mAdvancedOptions;

    bool SAVE_DATA_EDGE;
    bool SAVE_DATA_FIT;
    bool SAVE_DATA_EXTRA;

    // General

    void msWait(int ms);

protected:

    void keyPressEvent(QKeyEvent *event);

signals:

    void startTimer(int);
    void stopTimer();

    void showPlot();

public slots:

private slots:

    void onCombineData              ();
    void onSetCamAOI                ();
    void onCalibrateFrameRate       ();
    void onCropAOI                  ();
    void onDetectAllExperiments     ();
    void onDetectAllFrames          ();
    void onDetectAllTrials          ();
    void onDetectCurrentFrame       ();
    void onDialogueOpen             ();
    void onDirectorySelect          ();
    void onFlashStandbySlider       (int);
    void onImageNext                ();
    void onImagePrevious            ();
    void onLoadSession              ();
    void onPlotTrialData            ();
    void onQuitButtonClicked        ();
    void onResetFlashIntensity      ();
    void onResetParameters          ();
    void onSaveTrialData            ();
    void onSetAOIEyeLeft            ();
    void onSetAOIEyeRght            ();
    void onSetBeadDetection         (int);
    void onSetBeadAOIHght           (double);
    void onSetBeadAOIWdth           (double);
    void onSetCamAOIHght            (double);
    void onSetCamAOIWdth            (double);
    void onSetCamAOIXPos            (double);
    void onSetCamAOIYPos            (double);
    void onSetCameraAutoGain        (int);
    void onSetCameraBlackLevelMode  (int);
    void onSetCameraBlackLevelOffset(int);
    void onSetCameraExposure        (double);
    void onSetCameraFrameRate       (double);
    void onSetCameraFrameRateDesired(int);
    void onSetCameraGainBoost       (int);
    void onSetCameraHardwareGain    (int);
    void onSetCameraPixelClock      (int);
    void onSetCameraSubSampling     (int);
    void onSetAdvancedMode          (bool);
    void onSetDrawEdge              (int);
    void onSetDrawElps              (int);
    void onSetDrawHaar              (int);
    void onSetEyeAOIHght            (double);
    void onSetEyeAOIWdth            (double);
    void onSetFlashAOIHghtLeft      (int);
    void onSetFlashAOIWdthLeft      (int);
    void onSetFlashAOIXPosLeft      (int);
    void onSetFlashAOIYPosLeft      (int);
    void onSetFlashAOIHghtRght      (int);
    void onSetFlashAOIWdthRght      (int);
    void onSetFlashAOIXPosRght      (int);
    void onSetFlashAOIYPosRght      (int);
    void onSetFlashThreshold        (int);
    void onSetOfflineImage          (int);
    void onSetOfflineMode           (int);
    void onSetPupilPosition         (double, double);
    void onSetOnlineProcessing      (int);
    void onSetSaveDataAspectRatio   (int);
    void onSetSaveDataCircumference (int);
    void onSetSaveDataPosition      (int);
    void onSetTrialIndex            (int);
    void onSetTrialOffline          (int);
    void onStartRecordingManual     ();
    void onUpdateCameraImage        ();
    void onUpdateImageProcessed     (int);
    void onUpdateImageRaw           (int);

    // Advanced

    void onSetCurvatureMeasurement  (int);

    void onSetSaveDataEdge (int);
    void onSetSaveDataFit  (int);
    void onSetSaveDataExtra(int);

};

#endif // MAINWINDOW_H
