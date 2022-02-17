#pragma once

#include <QObject>
#include <QtTest>
#include "Speechassistant.h"
#include "test/commons.h"

class TestSpeechassistant : public QObject {

    Q_OBJECT;

    Speechassistant * cut_;

    QMediaCaptureSession * session_;
    QMediaRecorder * recorder_;
    QMediaFormat * format_;
    QAudioInput * input_;

    QMediaPlayer * player_;
    QAudioOutput * output_;

    StateLed * stateled_;
    Connector * connector_;
    BaseMicrophone * microphone_;
    Speaker * speaker_;
    FileInfoCollector * fileinfocollector_;

public:
    TestSpeechassistant() : QObject(nullptr) {};

    const QString val = "0";
    const string VALID_PATH = SOUNDS_PATH + val.toStdString() + LOCAL_FILE_ENDING;
private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void init();
    void cleanup();

    void testRecording_stateled();

    void testRecording_recorderstate();

    void testRecording_noMicrophone();

    void testSearchingAnswer_filledfileinfocollector();

    void testSearchingAnswer_emptyfileinfocollector();

    void testSearchingAnswer_filledfileinfocollector_withConnectionHandler();

    /*void testSearchingAnswer_stateled();

    void testPlayingAnswer_stateled();*/

    void testPlayingAnswer();

    void testPlayingError();

};
