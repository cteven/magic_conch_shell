#include "Battery.h"

Battery::Battery(int startvalue) : percentage(startvalue) {
    if(startvalue > 100) percentage = 100;
}

void Battery::setpercentage(unsigned int new_percentage) {
    if( new_percentage > 100 )
        percentage = 100;
    else
        percentage = new_percentage;

    emit sendupdate(percentage);
}

void Battery::setBatteryLed(BatteryLed * led)
{
    batteryled = led;

    connect(this, SIGNAL(sendupdate(uint)),batteryled,SLOT(setLed(uint)));
}

unsigned int Battery::getpercentage() const { return percentage;
}
