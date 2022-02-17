#pragma once

#include "Button.h"
#include "Battery.h"
#include "Speechassistant.h"
#include "Speaker.h"
#include "Cord.h"
#include "ConnectionHandler.h"

#include <QObject>

class SensorControl : public QObject
{
    Q_OBJECT;

    private:
        Button * language_button_;
        Button * voldown_button_;
        Button * volup_button_;
        Button * listening_button_;
        Cord * cord_;
        Speaker * speaker_;
        Battery * battery_;
        Speechassistant * speechassistant_;
        Connector * connector_;

    public:
        void start();
        Battery * getBattery();

        // setter
        void setLangButton( Button * );
        void setVolDownButton( Button * );
        void setVolUpButton( Button * );
        void setListeningButton( Button * );

        void setCord(class Cord * );
        void setSpeaker( Speaker * );
        void setBattery( Battery * );
        void setSpeechassistant( Speechassistant * );
        void setConnector( Connector * );

public slots:
        void langbutton_pressed();
        void voldown_button_pressed();
        void volup_button_pressed();
        void listening_button_pressed();
        void cord_pulled( int );
};

