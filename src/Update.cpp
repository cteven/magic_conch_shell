#include "Update.h"
#include "UpdateLed.h"
#include "Connector.h"
#include <QDebug>
#include <QThread>

void Update::setUpdateLed(UpdateLed * uled)
{
    led = uled;
}

void Update::overwrite_old()
{
    led->on();
    /*
     * overwrite the old version in memory
    */

    QThread::sleep(1);
    led->off();
}
