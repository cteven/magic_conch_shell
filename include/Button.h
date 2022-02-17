#pragma once

#include <QObject>

class Button: public QObject {
    protected:
        bool button_pressed;

    public:
        Button() : button_pressed(false) {};
        bool getbutton_pressed() const;

    public slots:
        void setbutton_pressed();
};
