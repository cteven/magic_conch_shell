#pragma once

#include <QObject>
#include "BatteryLed.h"

class BaseBattery : public QObject {
    Q_OBJECT

protected:
    unsigned int percentage;
    BatteryLed * batteryled;

public:
    //BaseBattery(int startvalue = 100) : percentage(startvalue) {};
    virtual unsigned int getpercentage() const = 0;
    virtual void setBatteryLed(BatteryLed *) = 0;


public slots:
        virtual void setpercentage(unsigned int) = 0;


signals:
    void sendupdate(unsigned int);

};
