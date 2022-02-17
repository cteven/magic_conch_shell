#pragma once

#include <QObject>
#include <QtTest>
#include "BatteryLed.h"

class TestBatteryLed : public QObject
{
    Q_OBJECT;

    BatteryLed * cut_;

public:
    TestBatteryLed() : QObject(nullptr) {};

    const unsigned int VALID_VALUE = 55;
    const unsigned int VALID_VALUE_ABOVE_HUNDRED = 155;


private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void init();
    void cleanup();


    // Test if the setLed(uint) Slot works and sets the value correctly
    // giving the BatteryLed obj. to a Battery mockup class, then emitting signal from mockup

    // 1.  Expected: set percentage of mockup to 55 -> battery_indicator = 55
    void testSettingBatteryIndicatorBySlot_ValidValue();

    // 2.  Expected: set percentage of mockup to 155 -> battery_indicator = 100
    void testSettingBatteryIndicatorBySlot_TooBigValue();

};
