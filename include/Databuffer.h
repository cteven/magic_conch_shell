#pragma once

#include "BaseDatabuffer.h"

using namespace std;

class Databuffer : public BaseDatabuffer {
    private:
        int file_size;
        string filepath;

    public:
        Databuffer(string);
        ~Databuffer();
        void set_filepath(string);
        string get_filepath() const;
        int getfile_size() const;
        void delete_file();
};
