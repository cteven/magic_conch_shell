#include <QUrl>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QMediaDevices>
#include <QAudioDevice>
#include <QDir>

#include "test/Microphone_mockup.h"
#include "commons.h"
#include <QMediaFormat>

using namespace std;

Microphone_mockup::Microphone_mockup(QMediaCaptureSession * session, QMediaRecorder * recorder,
                                     QMediaFormat * format, QAudioInput * input)
    : capture_session_(session)
{
    /*session->setRecorder(recorder);
    session->setAudioInput(input);
    input->setDevice(QMediaDevices::defaultAudioInput());

    format->setFileFormat(QMediaFormat::MP3);
    format->setAudioCodec(QMediaFormat::AudioCodec::MP3);
    session->recorder()->setMediaFormat(*format);

    session->recorder()->setAudioSampleRate(44100);
    session->recorder()->setAudioBitRate(64000);
    session->recorder()->setAudioChannelCount(1);
    session->recorder()->setQuality(QMediaRecorder::HighQuality);
    session->recorder()->setEncodingMode(QMediaRecorder::ConstantBitRateEncoding);*/
}

string Microphone_mockup::startrecord()
{
    /*int i = 0;
    QString path;
    while(true) {
        path = RECORDINGS_PATH + QString::fromStdString(to_string(i)) + SAVING_FILE_ENDING;
        QFile file(path);
        if(!file.exists()){
            capture_session_->recorder()->setOutputLocation(path);
            break;
        }
        i++;
    }

    capture_session_->recorder()->record();
    return path.toStdString();*/

    string ret = RECORDINGS_PATH;
    ret.append("1");
    ret.append(SAVING_FILE_ENDING);

    QDir filepath(QString::fromStdString(ret));
    filepath.makeAbsolute();

    return filepath.path().toStdString();
}

void Microphone_mockup::stoprecording()
{
    capture_session_->recorder()->stop();
/*
    string path = capture_session_->recorder()->outputLocation().toString().toStdString() + SAVING_FILE_ENDING;
    path.erase(0, strlen("file:///"));
    qDebug() << QString::fromStdString(path);
    return path;*/
}
