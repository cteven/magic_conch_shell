#pragma once
#include <QMainWindow>
#include <QLabel>
#include "SensorControl.h"
#include "Update.h"
#include "Physics.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    Button * language_button;
    Button * voldown_button;
    Button * volup_button;
    Button * listening_button;
    Cord * cord;

    QMediaPlayer * player;
    QAudioOutput * output;
    Speaker * speaker;

    Battery * battery;
    BatteryLed * batteryled;
    StateLed * stateled;
    Update * update;
    UpdateLed * updateled;

    Speechassistant * speechassistant;
    Connector * connector;
    FileInfoCollector * fileinfocollector;

    QMediaCaptureSession * session;
    QMediaRecorder * recorder;
    QMediaFormat * format;
    QAudioInput * input;
    Microphone * microphone;

    SensorControl * sensorcontrol;

    Physics * physics;

private slots:
    void listening_button_pressed();
    void cord_pulled_and_answered( int );
};
