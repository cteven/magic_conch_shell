#include "BatteryLed.h"
#include "Battery.h"
#include <QDebug>

BatteryLed::BatteryLed() : turned_on(false), battery_indicator(0)
{}

int BatteryLed::getbattery_indicator() const { return battery_indicator; }

void BatteryLed::setLed( unsigned int percentage ) {
    if( percentage > 100 )
        battery_indicator = 100;
    else
        battery_indicator = percentage;

    if( battery_indicator <= 10 )
        qDebug() << "BatteryLed: " << battery_indicator << " red";
    else
        qDebug() << "BatteryLed: " << battery_indicator << " green";
}
