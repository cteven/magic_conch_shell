#include "test/Update_mockup.h"

void Update_mockup::setUpdateLed(UpdateLed * uled)
{
    led = uled;
}

void Update_mockup::overwrite_old()
{
    led->on();
}
