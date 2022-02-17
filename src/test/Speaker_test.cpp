#include "test/Speaker_test.h"
#include <QDebug>
#include <QThread>

void TestSpeaker::init()
{
    player = new QMediaPlayer;
    output = new QAudioOutput;
    cut_ = new Speaker(player, output);
}

void TestSpeaker::cleanup()
{
    delete player;
    delete output;
    delete cut_;

    player = 0;
    output = 0;
    cut_ = 0;
}

void TestSpeaker::testChangeSpeakerVolume()
{
    cut_->setvolume(100);

    QVERIFY(output->volume() == 1);
}

void TestSpeaker::testPlaySound_ExistingFile()
{
    cut_->playSound(ERRSOUND_PATH);

    qDebug() << player->playbackState();

    QVERIFY(player->playbackState() == QMediaPlayer::PlayingState);
}

void TestSpeaker::testPlaySound_NotExistingFile()
{
    qDebug() << player->playbackState();
    cut_->playSound(NOT_EXISTING_ERRSOUND_PATH);

    qDebug() << player->playbackState();

    QVERIFY(player->playbackState() == QMediaPlayer::StoppedState);
}

void TestSpeaker::testPlayError_ExistingErrorNumber()
{
    cut_->play_err(1);

    qDebug() << player->playbackState();
    QVERIFY(player->playbackState() == QMediaPlayer::PlayingState);
}

void TestSpeaker::testPlayError_NotExistingErrorNumber()
{
    cut_->play_err(100);

    qDebug() << player->playbackState();
    QVERIFY(player->playbackState() == QMediaPlayer::StoppedState);
}
