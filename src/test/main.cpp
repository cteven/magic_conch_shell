#include <QtTest>
#include "test/Battery_test.h"
#include "test/BatteryLed_test.h"
#include "test/Databuffer_test.h"
#include "test/FileInfoCollector_test.h"
#include "test/ConnectionHandler_test.h"
#include "test/Speaker_test.h"
#include "test/Microphone_test.h"
#include "test/Speechassistant_test.h"

int main(int argc, char ** argv) {
    TestBattery testcasesBattery;
    QTest::qExec(&testcasesBattery,argc,argv);

    TestBatteryLed testcasesBatteryLed;
    QTest::qExec(&testcasesBatteryLed,argc,argv);

    TestDatabuffer testcasesDatabuffer;
    QTest::qExec(&testcasesDatabuffer, argc, argv);

    TestFileInfoCollector testcasesFileInfoCollector;
    QTest::qExec(&testcasesFileInfoCollector, argc, argv);

    TestConnectionHandler testcasesConnectionHandler;
    QTest::qExec(&testcasesConnectionHandler, argc, argv);

    TestSpeaker testcasesSpeaker;
    QTest::qExec(&testcasesSpeaker, argc, argv);

    TestMicrophone testcasesMicrophone;
    QTest::qExec(&testcasesMicrophone, argc, argv);

    TestSpeechassistant testcasesSpeechassistant;
    QTest::qExec(&testcasesSpeechassistant, argc, argv);

    return 0;

}
