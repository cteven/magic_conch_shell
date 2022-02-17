#pragma once

#include "Battery.h"
#include <QTimer>

class Physics: public QObject
{
    Q_OBJECT;

private:
    Battery * battery;
    QTimer timer;


private slots:
    void decreaseBatteryPercentage();

public:
    Physics(Battery *);

};

