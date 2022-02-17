#pragma once

#include "UpdateLed.h"

class BaseUpdate
{
    protected:
      UpdateLed * led;

    public:
        virtual void setUpdateLed(UpdateLed * ) = 0;
        virtual void overwrite_old() = 0;
};
