#include "FileInfoCollector.h"
#include <QDebug>

string FileInfoCollector::get_filepath() const {
    if(buflen > 0)
        return buffers[buflen-1]->get_filepath();
    return "";
}

int FileInfoCollector::getfile_size() const
{   if(buflen > 0)
        return buffers[buflen-1]->getfile_size();
    return 0;
}

void FileInfoCollector::save_file(string filepath) {
    buffers.push_back(new Databuffer(filepath));
    buflen++;
}

void FileInfoCollector::pop_back() {
    if(buflen > 0) {
        buffers.pop_back();
        buflen--;
    }
}

/*void FileInfoCollector::remove(Databuffer * buffer) {
    string bufpath = buffer->get_filepath();

    for(int i = 0; i < buflen; i++) {
        if( buffers[buflen - 1 - i]->get_filepath() == bufpath)
            buffers.erase(buffers.end() - 1 - i);
    }
    buflen--;
}*/

void FileInfoCollector::remove(string path) {
    if(buflen > 0) {
        for(int i = 0; i < buflen; i++) {
            if( buffers[buflen - 1 - i]->get_filepath() == path) {
                buffers.erase(buffers.end() - 1 - i);
                break;
            }
        }
        buflen--;
    }
}

/*
Databuffer * FileInfoCollector::searchDatabuffer(string path) {
    for(int i = 0; i < buflen; i++) {
        if( buffers[i]->get_filepath() == path)
            return buffers[i];
    }
    return nullptr;
}
*/
