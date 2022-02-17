#pragma once

#include "BaseBattery.h"

class Battery : public BaseBattery {

private:
    unsigned int percentage;
    BatteryLed * batteryled;

public:
    Battery(int startvalue = 100);
    unsigned int getpercentage() const override;
    void setBatteryLed(BatteryLed *) override;

public slots:
    void setpercentage(unsigned int) override;

signals:
    using BaseBattery::sendupdate;

};
