#include "UpdateLed.h"
#include <QDebug>

void UpdateLed::on() {
    qDebug() << "UpdateLed: on";
    turned_on = true;
}

void UpdateLed::off() {
    qDebug() << "UpdateLed: off";
    turned_on = false;
}

bool UpdateLed::getstate() const { return turned_on; }
