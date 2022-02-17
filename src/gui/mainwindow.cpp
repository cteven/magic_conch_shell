#include "gui/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    language_button = new Button;
    voldown_button = new Button;
    volup_button = new Button;
    listening_button = new Button;
    cord = new Cord;

    player = new QMediaPlayer;
    output = new QAudioOutput;
    speaker = new Speaker(player, output);

    battery = new Battery;
    speechassistant = new Speechassistant;
    connector = new ConnectionHandler;

    fileinfocollector = new FileInfoCollector;

    session = new QMediaCaptureSession;
    recorder = new QMediaRecorder;
    format = new QMediaFormat;
    input = new QAudioInput;

    microphone = new Microphone(session, recorder,format, input);

    speechassistant->setfileinfocollector(fileinfocollector);
    speechassistant->setmicrophone(microphone);
    speechassistant->setspeaker(speaker);
    speechassistant->setconnector(connector);

    sensorcontrol = new SensorControl;

    sensorcontrol->setLangButton( language_button);
    sensorcontrol->setVolDownButton( voldown_button );
    sensorcontrol->setVolUpButton( volup_button );
    sensorcontrol->setListeningButton( listening_button );

    sensorcontrol->setCord( cord );
    sensorcontrol->setSpeaker( speaker );
    sensorcontrol->setBattery( battery );
    sensorcontrol->setSpeechassistant( speechassistant );
    sensorcontrol->setConnector( connector );

    connect(ui->ChangeLanButton, SIGNAL(clicked()), sensorcontrol, SLOT(langbutton_pressed()));
    connect(ui->CordSlider, SIGNAL(sliderMoved(int)), sensorcontrol, SLOT(cord_pulled(int)));
    connect(ui->ListenButton, SIGNAL(clicked()), sensorcontrol, SLOT(listening_button_pressed()));
    connect(ui->VolDownButton, SIGNAL(clicked()), sensorcontrol, SLOT(voldown_button_pressed()));
    connect(ui->VolUpButton, SIGNAL(clicked()), sensorcontrol, SLOT(volup_button_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
