#pragma once

#include <string>
#include <vector>

#include "Speaker.h"
#include "FileInfoCollector.h"
#include "Microphone.h"
#include "StateLed.h"
#include "Connector.h"

enum lang{ kGerman = 0, kEnglish = 1 };

class Speechassistant
{
    private:
        lang language;
        std::string answer_path_;
       // bool Answer_found;
        StateLed * stateled_;
        Connector * connector_;
        BaseMicrophone * microphone_;
        Speaker * speaker_;
        FileInfoCollector * fileinfocollector_;

    public:
        Speechassistant() {};
        Speechassistant(StateLed *, Connector *, BaseMicrophone *, Speaker *, FileInfoCollector *);
        void change_language();
        void record();
        void stoprecord();
        bool search_answer();
        void play_answer();
        void play_error();

        bool getlistening() const;

        void setstateled( StateLed * );
        void setconnector( Connector * );
        void setmicrophone( BaseMicrophone * );
        void setspeaker( Speaker * );
        void setfileinfocollector( FileInfoCollector * );
};
