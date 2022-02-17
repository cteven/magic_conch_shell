#pragma once
#include <QMainWindow>
#include <QLabel>
#include "SensorControl.h"

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
    Speechassistant * speechassistant;
    Connector * connector;
    FileInfoCollector * fileinfocollector;

    QMediaCaptureSession * session;
    QMediaRecorder * recorder;
    QMediaFormat * format;
    QAudioInput * input;
    Microphone * microphone;

    SensorControl * sensorcontrol;
};
