#include "test/Battery_test.h"
#include "BatteryLed.h"

void TestBattery::init()
{
    cut_ = new Battery;
    QVERIFY(cut_->getpercentage() == 100);
}

void TestBattery::cleanup()
{
    delete cut_;
    cut_ = 0;
}

void TestBattery::testSetValidValue()
{
    cut_->setpercentage(VALID_VALUE);
    QVERIFY(cut_->getpercentage() == VALID_VALUE);
}

void TestBattery::testSetTooBigValue()
{
    cut_->setpercentage(VALID_VALUE_ABOVE_HUNDRED);
    QVERIFY(cut_->getpercentage() == 100);
}

void TestBattery::testConstructorValidValue()
{
    delete cut_;
    cut_ = new Battery(VALID_VALUE);
    QVERIFY(cut_->getpercentage() == VALID_VALUE);
}

void TestBattery::testConstructorTooBigValue()
{
    delete cut_;
    cut_ = new Battery(VALID_VALUE_ABOVE_HUNDRED);
    QVERIFY(cut_->getpercentage() == 100);
}

void TestBattery::testBatteryLedInjectionAndConnectionValidValue()
{
    BatteryLed * batteryled = new BatteryLed;
    cut_->setBatteryLed(batteryled);

    cut_->setpercentage(VALID_VALUE);

    QVERIFY(batteryled->getbattery_indicator() == VALID_VALUE);
}

void TestBattery::testBatteryLedInjectionAndConnectionTooBigValue()
{
    BatteryLed * batteryled = new BatteryLed;
    cut_->setBatteryLed(batteryled);

    cut_->setpercentage(VALID_VALUE_ABOVE_HUNDRED);

    QVERIFY(batteryled->getbattery_indicator() == 100);
}
