#include "ConnectionHandler.h"
#include "commons.h"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <time.h>
//#include <unistd.h>

#include <QString>
#include <QFile>
#include <QDir>

#include <QDebug>

using namespace std;

ConnectionHandler::~ConnectionHandler()
{
    //close(socket);
}

int ConnectionHandler::sendData(string path)
{
    // sending the data from path to the current socket
    // return error code if error occurs
    return 0;
}

string ConnectionHandler::receiveData()
{
    srand(time(NULL));
    QString path = SOUNDS_PATH;

    while(true) {
        QString tmp = SOUNDS_PATH;
        int rnd = rand() % LOCAL_FILECOUNT;


        QString appendthis = QString::fromStdString(to_string(rnd));
        tmp.append(appendthis);
        tmp.append(LOCAL_FILE_ENDING);

        QDir filepath(tmp);
        filepath.makeAbsolute();

        QFile file(filepath.path());

        if( file.exists() == true ) {
            path = filepath.path();
            break;
        }
     }

    qDebug() << path;
    return path.toStdString();
}

int ConnectionHandler::connectforAnswer()
{
    // return error code if error occurs
    return 0;
}

int ConnectionHandler::connectforUpdate()
{
    // return error code if error occurs
    return 0;
}


string ConnectionHandler::searchAnswer(string filepath)
{
    if(filepath.empty())
        return "";
    // connectforAnswer() always returns 0 since there is nothing to connect to
    int err = connectforAnswer();
    if( err ){
        cerr << "error occured while connecting to Server: " << err;
        return nullptr;
    }
    err = sendData(filepath);
    if( err ){
        cerr << "error occured while sending Data: " << err;
        return nullptr;
    }

    return receiveData();
}

bool ConnectionHandler::searchUpdate()
{

    // connectforUpdate() always returns 0 since there is nothing to connect to
    int err = connectforUpdate();
    if( err ){
        cerr << "error occured: " << err;
        return false;
    }

    return false;
}

void ConnectionHandler::Update()
{
    update_->overwrite_old();
}

void ConnectionHandler::setfileinfocollector(FileInfoCollector * collector) {
    fileinfocollector_ = collector;
}

void ConnectionHandler::setUpdateObj(class BaseUpdate * upd)
{
    update_ = upd;
}

