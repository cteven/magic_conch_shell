#pragma once

#include <QObject>
#include "ConnectionHandler.h"

class TestConnectionHandler : public QObject
{
    Q_OBJECT;

    ConnectionHandler * cut_;

public:
    TestConnectionHandler() : QObject(nullptr) {};


private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void init();
    void cleanup();
/*
    // Test if sending data to a server works
    // Expected: returns 0 since there is no server yet
    void testSendingData();

    // Test if receiving data from the servers works
    // Expected: returns "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/1.mp3"
    void testReceivingData();

    // Test if connection to the server that provides the audio-answers works
    // Expected: returns errorcode 0 since there is no server
    void testConnectingToAnswerServer();

    // Test if connection to the server that provides the Updates works
    // Expected: returns errorcode 0 since there is no server
    void testConnectingToUpdateServer();
*/
    // Test which connects to server, then receives answer
    // Expected: should return:
    // "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/1.mp3"
    void testSearchingForAnswer_emptyString();

    void testSearchingForAnswer();

    // Test which connects to server, then asks if an update is available
    // Expected: returns false because there is no update to be done and no server to ask
    void testSearchingForUpdate();

    // Test if calling the Update classes overwrite_old method works
    // Expected: Update class has a UpdateLed class dependency whose on() method should get called
    //  means: UpdateLed -> getstate() should return true
    void testUseUpdateClassToUpdateProgram();


};
