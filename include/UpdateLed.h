#pragma once

class UpdateLed {
    private:
        bool turned_on;

    public:
        bool getstate() const;
        void off();
        void on();
};
