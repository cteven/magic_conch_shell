#include "Physics.h"

void Physics::decreaseBatteryPercentage()
{
    unsigned int percentage = battery->getpercentage();
    battery->setpercentage(percentage-1);
}

Physics::Physics(Battery * batt) : battery(batt) {
    timer.setInterval(2*1000*60);  // 2 min timer interval

    connect(&timer, SIGNAL(timeout()), this, SLOT(decreaseBatteryPercentage()));

    timer.start();
}
