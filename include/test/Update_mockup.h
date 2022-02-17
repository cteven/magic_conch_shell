#pragma once

#include "UpdateLed.h"
#include "BaseUpdate.h"

class Update_mockup : public BaseUpdate
{
    private:
        UpdateLed * led;

    public:
        void setUpdateLed(UpdateLed *);
        void overwrite_old();
};
