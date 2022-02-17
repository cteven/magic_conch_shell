#pragma once

#include <string>

using namespace std;

class BaseDatabuffer {
    protected:
        int file_size;
        string filepath;

    public:
        //BaseDatabuffer(string path) : file_size(0), filepath(path) {};
        //~BaseDatabuffer();
        virtual void set_filepath(string) = 0;
        virtual string get_filepath() const = 0;
        virtual int getfile_size() const = 0;
        virtual void delete_file() = 0;
};
