#pragma once

#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QAudioInput>
#include <string>

using namespace std;

class BaseMicrophone
{
    private:
        QMediaCaptureSession * capture_session_;

    public:
        //BaseMicrophone(QMediaCaptureSession * session, QMediaRecorder * recorder, QMediaFormat * format, QAudioInput * input);
        virtual ~BaseMicrophone() {};
        virtual string startrecord() = 0;
        virtual void stoprecording() = 0;
};
