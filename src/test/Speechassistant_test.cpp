#include "test/Speechassistant_test.h"
#include "ConnectionHandler.h"
#include "Microphone.h"
#include "commons.h"
#include <QDir>


void TestSpeechassistant::init()
{

    session_ = new QMediaCaptureSession;
    recorder_ = new QMediaRecorder;
    format_ = new QMediaFormat;
    input_ = new QAudioInput;

    player_ = new QMediaPlayer;
    output_ = new QAudioOutput;

    stateled_ = new StateLed;
    connector_ = new ConnectionHandler;
    microphone_ = new Microphone(session_, recorder_, format_, input_);
    speaker_ = new Speaker(player_, output_);
    fileinfocollector_ = new FileInfoCollector;
    cut_ = new Speechassistant(stateled_, connector_, microphone_, speaker_, fileinfocollector_);
}

void TestSpeechassistant::cleanup()
{
    delete session_;
    delete recorder_;
    delete format_;
    delete input_;

    delete player_;
    delete output_;

    delete stateled_;
    delete connector_;
    delete microphone_;
    delete speaker_;
    delete fileinfocollector_;
    delete cut_;
    cut_ = 0;
}

void TestSpeechassistant::testRecording_stateled()
{
    cut_->record();
    QVERIFY(stateled_->getstate() == state::kListening);
}

void TestSpeechassistant::testRecording_recorderstate()
{
    cut_->record();
    QVERIFY(recorder_->recorderState() == QMediaRecorder::RecorderState::RecordingState);
}

void TestSpeechassistant::testRecording_noMicrophone()
{
    delete cut_;
    cut_ = new Speechassistant(stateled_, connector_, nullptr, speaker_, fileinfocollector_);

    cut_->record();
    QVERIFY(recorder_->recorderState() == QMediaRecorder::RecorderState::StoppedState);
}

void TestSpeechassistant::testSearchingAnswer_filledfileinfocollector()
{
    QString path = SOUNDS_PATH + QString::fromStdString("0") + LOCAL_FILE_ENDING;
    QDir filepath(path);
    filepath.makeAbsolute();

    fileinfocollector_->save_file(filepath.path().toStdString());

    QVERIFY(cut_->search_answer() == true);
}

void TestSpeechassistant::testSearchingAnswer_emptyfileinfocollector()
{
    QVERIFY(cut_->search_answer() == false);
}

void TestSpeechassistant::testSearchingAnswer_filledfileinfocollector_withConnectionHandler()
{
    QString path = SOUNDS_PATH + QString::fromStdString("0") + LOCAL_FILE_ENDING;
    QString p2 = SOUNDS_PATH + QString::fromStdString("1") + LOCAL_FILE_ENDING;

    QDir fpath(path);
    fpath.makeAbsolute();
    path = fpath.path();

    QDir fpath2(p2);
    fpath2.makeAbsolute();
    p2 = fpath2.path();

    fileinfocollector_->save_file(fpath.path().toStdString());
    cut_->search_answer();

    QVERIFY(fileinfocollector_->get_filepath() == path.toStdString() || fileinfocollector_->get_filepath() == p2.toStdString());
}
/*
void TestSpeechassistant::testSearchingAnswer_stateled()
{
    cut_->search_answer();
    QVERIFY(stateled_->getstate() == state::kAnalysing);
}

void TestSpeechassistant::testPlayingAnswer_stateled()
{
    cut_->play_answer();
    QVERIFY(stateled_->getstate() == state::kIdle);
}
*/
void TestSpeechassistant::testPlayingAnswer()
{
    connector_->setfileinfocollector(fileinfocollector_);

    QDir filepath(QString::fromStdString(VALID_PATH));
    filepath.makeAbsolute();
    QString path = filepath.path();

    string valid_path = path.toStdString();

    fileinfocollector_->save_file(valid_path);
    cut_->search_answer();
    cut_->play_answer();
    QVERIFY(player_->playbackState() == QMediaPlayer::PlayingState);
}

void TestSpeechassistant::testPlayingError()
{
    QDir filepath(QString::fromStdString(VALID_PATH));
    filepath.makeAbsolute();
    QString path = filepath.path();

    string valid_path = path.toStdString();

    fileinfocollector_->save_file(valid_path);
    cut_->search_answer();
    cut_->play_error();
    QVERIFY(player_->playbackState() == QMediaPlayer::PlayingState);
}
