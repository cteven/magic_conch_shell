#include "Physics.h"

Physics::Physics(Battery * batt) : battery(batt) {
    timer.setInterval(2*1000*60);  // 2 min timer interval

    connect(this, SIGNAL(timeout()), battery, SLOT(setpercentage(uint)));

    timer.start();
}
