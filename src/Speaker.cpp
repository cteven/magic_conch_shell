#include "Speaker.h"
#include "commons.h"
#include <QString>
#include <QFile>
#include <QDir>

using namespace std;

Speaker::Speaker(QMediaPlayer * player, QAudioOutput * output): mediaplayer(player), audiooutput(output) {
    mediaplayer->setAudioOutput(audiooutput);
    audiooutput->setVolume(50);
}

void Speaker::setvolume( float volume ) {
    audiooutput->setVolume(volume);
}

float Speaker::getvolume() const
{
    return audiooutput->volume();
}

void Speaker::playSound( string path ) {
    QString qpath = QString::fromStdString(path);
    QFile file(qpath);
    if( file.exists() ) {
        mediaplayer->setSource(QUrl::fromLocalFile(qpath));
        qDebug() << __FUNCTION__ << " " << mediaplayer->source();
        mediaplayer->play();
    }

}

void Speaker::play_err( int errnumber ) {
    errsound_path = ERROR_SOUNDS_PATH + to_string(errnumber) + LOCAL_FILE_ENDING;
    QDir filepath(QString::fromStdString(errsound_path));
    filepath.makeAbsolute();
    QString path = filepath.path();

    qDebug() << "errsound_path" << path;

    QFile file(path);
    if( file.exists() ) {
        mediaplayer->setSource(QUrl::fromLocalFile(path));
        qDebug() << mediaplayer->source();
        mediaplayer->play();
    }
}

QMediaPlayer::PlaybackState Speaker::getplaybackstate() const
{
    return mediaplayer->playbackState();
}

void Speaker::setMediaPlayer(QMediaPlayer * player)
{
    mediaplayer = player;
}

void Speaker::setAudioOutput(QAudioOutput * output)
{
    audiooutput = output;
}
