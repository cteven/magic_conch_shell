#pragma once

#include "Connector.h"
#include "BaseUpdate.h"

class ConnectionHandler: public Connector
{

private:
    int socket;
    class BaseUpdate * update_;
    FileInfoCollector * fileinfocollector_;

    int sendData(std::string);
    std::string receiveData();
    int connectforAnswer();
    int connectforUpdate();

public:
    ~ConnectionHandler();
    std::string searchAnswer(std::string) override;
    // returns true, if update available
    bool searchUpdate() override;
    void Update() override;

    void setfileinfocollector(FileInfoCollector * ) override;
    void setUpdateObj(class BaseUpdate *);

};
