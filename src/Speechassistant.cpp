#include "Speechassistant.h"
#include "Microphone.h"
#include "StateLed.h"
#include "commons.h"

#include <ctime>
#include <iostream>
#include <ctime>
#include <QThread>

#include <QDebug>

void Speechassistant::change_language() {

       if (language == kGerman) language = kEnglish;
       else language = kGerman;
}

Speechassistant::Speechassistant( StateLed * stateled, Connector * connector,
                                  BaseMicrophone * microphone, Speaker * speaker,
                                  FileInfoCollector * fileinfocollector
                                 )
    : stateled_(stateled),
      connector_(connector),
      microphone_(microphone),
      speaker_(speaker),
      fileinfocollector_(fileinfocollector)
{}

void Speechassistant::record() {
    qDebug() << "speechassistant - record started";
    if(microphone_ != nullptr) {
        stateled_->setstate(kListening);

        // start recording
        QString recordpath = QString::fromStdString(microphone_->startrecord());

        fileinfocollector_->save_file(recordpath.toStdString());
    }
    else {
        //play_Answer( ERROR_SOUND_PATH )
        qDebug() << "microphone not set";
    }
}

bool Speechassistant::search_answer() {
    stateled_->setstate(kAnalysing);

    string path = fileinfocollector_->get_filepath();

    answer_path_ = connector_->searchAnswer(path);


    if(answer_path_.empty())
        return false;

    fileinfocollector_->save_file(answer_path_);

    return true;
}

void Speechassistant::play_answer() {
    stateled_->setstate(kReplying);

    speaker_->playSound(answer_path_);

    fileinfocollector_->remove(answer_path_);

    stateled_->setstate(kIdle);
}

void Speechassistant::play_error() {
    stateled_->setstate(kReplying);

    srand(time(nullptr));

    speaker_->play_err(rand() % LOCAL_FILECOUNT); // replace 5 with the total number of available error sounds

    //while(speaker_->getplaybackstate() == QMediaPlayer::PlaybackState::PlayingState);
    stateled_->setstate(kIdle);
}

bool Speechassistant::getlistening() const
{
    QMediaRecorder::RecorderState state = microphone_->getrecordingstate();
    if( state == QMediaRecorder::StoppedState || state == QMediaRecorder::PausedState )
        return false;
    return true;
}

void Speechassistant::setstateled(StateLed * stateled)
{
    stateled_ = stateled;
}

void Speechassistant::stoprecord()
{
    microphone_->stoprecording();
}

void Speechassistant::setconnector(Connector * con)
{
    connector_ = con;
}

void Speechassistant::setmicrophone(BaseMicrophone * microphone)
{
    microphone_ = microphone;
}

void Speechassistant::setspeaker(Speaker * speaker)
{
    speaker_ = speaker;
}

void Speechassistant::setfileinfocollector(FileInfoCollector * fileinfocollector)
{
    fileinfocollector_ = fileinfocollector;
}

