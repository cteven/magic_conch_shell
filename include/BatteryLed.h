#pragma once

#include <QObject>

class BatteryLed : public QObject {

    Q_OBJECT

private:
    bool turned_on;
    unsigned int battery_indicator;

public:
    BatteryLed();
    int getbattery_indicator() const;

public slots:
    void setLed( unsigned int );

};
