#pragma once

#include <string>
#include <QMediaPlayer>
#include <QAudioOutput>

class Speaker
{
    private:
        std::string errsound_path;
        QMediaPlayer * mediaplayer;
        QAudioOutput * audiooutput;

    public:
        Speaker(QMediaPlayer *, QAudioOutput *);
        void setvolume( float volume );
        float getvolume() const;
        void playSound( std::string path );
        void play_err( int errnumber );

        QMediaPlayer::PlaybackState getplaybackstate() const;

        void setMediaPlayer(QMediaPlayer * );
        void setAudioOutput(QAudioOutput * );
};
