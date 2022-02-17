#include "SensorControl.h"
#include "ConnectionHandler.h"

#include <QDebug>

void SensorControl::start() {
    while(true) {
        if ( language_button_->getbutton_pressed() == true ) {
            speechassistant_->change_language();
        }
        if ( voldown_button_->getbutton_pressed() == true ) {
            float vol = speaker_->getvolume();
            speaker_->setvolume(vol-1);
        }
        if ( volup_button_->getbutton_pressed() == true ) {
            float vol = speaker_->getvolume();
            speaker_->setvolume(vol+1);
        }
        if ( listening_button_->getbutton_pressed() == true ) {
            speechassistant_->record();

        }
        if( cord_->getcord_pull() >= 50 ) {
            bool answer_found = speechassistant_->search_answer();

            if( answer_found )
                speechassistant_->play_answer();
            else
                speechassistant_->play_error();
        }
    }
}

Battery *SensorControl::getBattery() { return battery_; }

void SensorControl::setLangButton(Button * lang_button)
{
    language_button_ = lang_button;
}

void SensorControl::setVolDownButton(Button * voldown_button)
{
    voldown_button_ = voldown_button;
}

void SensorControl::setVolUpButton(Button * volup_button)
{
    volup_button_ = volup_button;
}

void SensorControl::setListeningButton(Button * listening_button)
{
    listening_button_ = listening_button;
}

void SensorControl::setCord(class Cord * cord)
{
    cord_ = cord;
}

void SensorControl::setSpeaker(Speaker * speaker)
{
    speaker_ = speaker;
}

void SensorControl::setBattery(Battery * battery)
{
    battery_ = battery;
}

void SensorControl::setSpeechassistant(Speechassistant * speechassistant)
{
    speechassistant_ = speechassistant;
}

void SensorControl::setConnector(Connector * connector)
{
    connector_ = connector;
}

// --------------------------------slots------------------------------------------

void SensorControl::langbutton_pressed()
{
    qDebug() << "changed language";
    speechassistant_->change_language();
}

void SensorControl::voldown_button_pressed()
{
    qDebug() << "VolDown";
    float vol = speaker_->getvolume();
    speaker_->setvolume(vol-1);
}

void SensorControl::volup_button_pressed()
{
    qDebug() << "VolUp";
    float vol = speaker_->getvolume();
    speaker_->setvolume(vol+1);
}

void SensorControl::listening_button_pressed()
{
    listening_button_->setbutton_pressed();
    qDebug() << "listening";
    speechassistant_->record();
}

void SensorControl::cord_pulled( int pull )
{
    qDebug() << "cord pulled to: " << pull;
    if ( pull >= 50 && speechassistant_->getlistening() ) {
        speechassistant_->stoprecord();
        bool answer_found = speechassistant_->search_answer();

        if( answer_found )
            speechassistant_->play_answer();
        else
            speechassistant_->play_error();
    }

}
