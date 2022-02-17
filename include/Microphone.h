#pragma once

#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QAudioInput>
#include <string>

#include "BaseMicrophone.h"

using namespace std;

class Microphone : public BaseMicrophone
{
    private:
        QMediaCaptureSession * capture_session_;

    public:
        Microphone(QMediaCaptureSession *, QMediaRecorder *, QMediaFormat * , QAudioInput *);
        ~Microphone() {};
        string startrecord();
        void stoprecording();
        QMediaRecorder::RecorderState getrecordingstate() const;
};
