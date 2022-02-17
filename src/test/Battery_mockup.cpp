#include "test/Battery_mockup.h"

Battery_mockup::Battery_mockup(int startvalue) : percentage(startvalue)
{
    if(startvalue > 100) percentage = 100;
}

unsigned int Battery_mockup::getpercentage() const
{
    // return any value so the method isn't empty
    return 100;
}

void Battery_mockup::setpercentage(unsigned int p)
{
    emit sendupdate(p);
}

void Battery_mockup::setBatteryLed(BatteryLed * led)
{
    batteryled = led;

    connect(this, SIGNAL(sendupdate(uint)), batteryled, SLOT(setLed(uint)));
}
