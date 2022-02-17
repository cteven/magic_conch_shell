#include "test/BatteryLed_test.h"
#include "test/Battery_mockup.h"

#include <QtTest>

void TestBatteryLed::init()
{
    cut_ = new BatteryLed;
}

void TestBatteryLed::cleanup()
{
    delete cut_;
    cut_ = 0;
}

void TestBatteryLed::testSettingBatteryIndicatorBySlot_ValidValue()
{
    BaseBattery * batt = new Battery_mockup;
    batt->setBatteryLed(cut_);

    batt->setpercentage(VALID_VALUE);
    QVERIFY(cut_->getbattery_indicator() == VALID_VALUE);
}

void TestBatteryLed::testSettingBatteryIndicatorBySlot_TooBigValue()
{
    BaseBattery * batt = new Battery_mockup;
    batt->setBatteryLed(cut_);

    batt->setpercentage(VALID_VALUE_ABOVE_HUNDRED);
    QVERIFY(cut_->getbattery_indicator() == 100);
}
