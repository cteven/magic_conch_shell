#pragma once

#include "UpdateLed.h"
#include "BaseUpdate.h"

class Update : public BaseUpdate
{
    private:
      UpdateLed * led;

    public:
        void setUpdateLed(UpdateLed * );
        void overwrite_old();
};
