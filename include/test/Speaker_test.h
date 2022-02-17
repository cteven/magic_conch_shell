#pragma once

#include <QObject>
#include <QtTest>
#include "Speaker.h"

using namespace std;

class TestSpeaker : public QObject
{
    Q_OBJECT;

    Speaker * cut_;
    QMediaPlayer * player;
    QAudioOutput * output;

public:
    TestSpeaker() : QObject(nullptr) {}

    const string ERRSOUND_PATH = "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/error_sounds/1.mp3";
    const string NOT_EXISTING_ERRSOUND_PATH = "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/error_sounds/100.mp3";

private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void init();
    void cleanup();

    void testChangeSpeakerVolume();

    void testPlaySound_ExistingFile();

    void testPlaySound_NotExistingFile();

    void testPlayError_ExistingErrorNumber();

    void testPlayError_NotExistingErrorNumber();

};
