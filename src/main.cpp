#include <iostream>
#include "SensorControl.h"

using namespace std;

int main()
{
    Button * language_button = new Button;
    Button * voldown_button = new Button;
    Button * volup_button = new Button;
    Button * listening_button = new Button;
    Cord * cord = new Cord;

    QMediaPlayer * player = new QMediaPlayer;
    QAudioOutput * output = new QAudioOutput;
    Speaker * speaker = new Speaker(player, output);

    Battery * battery = new Battery;
    Speechassistant * speechassistant = new Speechassistant;
    Connector * connector = new ConnectionHandler;

    FileInfoCollector * fileinfocollector = new FileInfoCollector;

    QMediaCaptureSession * session = new QMediaCaptureSession;
    QMediaRecorder * recorder = new QMediaRecorder;
    QMediaFormat * format = new QMediaFormat;
    QAudioInput * input = new QAudioInput;

    Microphone * microphone = new Microphone(session, recorder,format, input);

    speechassistant->setfileinfocollector(fileinfocollector);
    speechassistant->setmicrophone(microphone);
    speechassistant->setspeaker(speaker);
    speechassistant->setconnector(connector);

    SensorControl * sensorcontrol = new SensorControl;

    sensorcontrol->setLangButton( language_button);
    sensorcontrol->setVolDownButton( voldown_button );
    sensorcontrol->setVolUpButton( volup_button );
    sensorcontrol->setListeningButton( listening_button );

    sensorcontrol->setCord( cord );
    sensorcontrol->setSpeaker( speaker );
    sensorcontrol->setBattery( battery );
    sensorcontrol->setSpeechassistant( speechassistant );
    sensorcontrol->setConnector( connector );

    return 0;
}
