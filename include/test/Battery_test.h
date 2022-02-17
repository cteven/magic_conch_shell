#pragma once

#include <QtTest>
#include <QObject>
#include "Battery.h"

class TestBattery : public QObject {

    Q_OBJECT;

    Battery * cut_;

public:
    TestBattery() : QObject(nullptr) {};
    const unsigned int VALID_VALUE = 55;
    const unsigned int VALID_VALUE_ABOVE_HUNDRED = 155;


private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void init();
    void cleanup();

    // Test setting Battery percentage to a valid value that is <100
    // Expected: set percentage to 55 -> getpercentage() == 55
    void testSetValidValue();

    // Test setting Battery percentage to a valid value that is >100
    // Expected: set percentage to 155 -> getpercentage() == 100
    void testSetTooBigValue();

    // Test using the constructor to set the percentage value to a valid value that is <100
    // Expected: create class with value 55 -> getpercentage() == 55
    void testConstructorValidValue();

    // Test using the constructor to set the percentage value to a valid value that is >100
    // Expected: create class with value 155 -> getpercentage() == 100
    void testConstructorTooBigValue();

    // Test giving the Battery Class a Pointer to a BatteryLed class
    //  which connects both classes via sendupdate(uint) and setLed(uint)

    // Expected: setpercentage() automatically updates BatteryLed battery_indicator to:
    // 1.  - a valid value <100
    void testBatteryLedInjectionAndConnectionValidValue();

    // 2.  - a valid value >100
    void testBatteryLedInjectionAndConnectionTooBigValue();

};
