#include "test/Microphone_test.h"
#include <string>
#include <QFile>

using namespace std;

void TestMicrophone::init()
{
    session = new QMediaCaptureSession;
    recorder = new QMediaRecorder;
    format = new QMediaFormat;
    input = new QAudioInput;

    cut_ = new Microphone(session, recorder,format, input);
}

void TestMicrophone::cleanup()
{
    QFile file(QString::fromStdString(filepath));
    file.remove();

    delete session;
    delete format;
    delete input;

    delete cut_;


    session = 0;
    format = 0;
    input = 0;
    cut_ = 0;
}

void TestMicrophone::testStartRecording()
{
    filepath = cut_->startrecord();

    QVERIFY(session->recorder()->recorderState() == QMediaRecorder::RecordingState);

    /*QFile file(QString::fromStdString(filepath));
    qDebug() << file.exists();
    file.remove();*/
}

void TestMicrophone::testStartRecording_filepath()
{
    filepath = cut_->startrecord();
    cut_->stoprecording();

    QFile file(QString::fromStdString(filepath));
    QVERIFY(file.exists());
}

void TestMicrophone::testStopRecording()
{
    cut_->stoprecording();

    QVERIFY(session->recorder()->recorderState() == QMediaRecorder::StoppedState);
}
