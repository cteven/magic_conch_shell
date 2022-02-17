#pragma once

#include <string>

#include "FileInfoCollector.h"

class Connector
{
    public:
        virtual ~Connector() {};
        virtual std::string searchAnswer(std::string) = 0;

        // returns true, if update available
        virtual bool searchUpdate() = 0;

        virtual void Update() = 0;

        virtual void setfileinfocollector( FileInfoCollector * ) = 0;
};
