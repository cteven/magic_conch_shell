#pragma once

#include <QtTest>
#include <QObject>
#include <QString>
#include "Microphone.h"

class TestMicrophone : public QObject
{
    Q_OBJECT;

    Microphone * cut_;
    QMediaCaptureSession * session;
    QMediaRecorder * recorder;
    QMediaFormat * format;
    QAudioInput * input;
    string filepath;


public:
    TestMicrophone() : QObject(nullptr) {};

private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void init();
    void cleanup();

    void testStartRecording();

    void testStartRecording_filepath();

    void testStopRecording();

};

