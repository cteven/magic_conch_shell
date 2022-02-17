#pragma once

#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QAudioInput>
#include <string>

#include "BaseMicrophone.h"

using namespace std;

class Microphone_mockup : public BaseMicrophone
{
    private:
        QMediaCaptureSession * capture_session_;

    public:
        Microphone_mockup(QMediaCaptureSession *, QMediaRecorder *, QMediaFormat * , QAudioInput *);
        ~Microphone_mockup() {};
        string startrecord() override;
        void stoprecording() override;
};
