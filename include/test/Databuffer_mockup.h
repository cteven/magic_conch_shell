#pragma once

#include <string>
#include "BaseDatabuffer.h"

using namespace std;

class Databuffer_mockup : public BaseDatabuffer {
    private:
        int file_size;
        string filepath;

    public:
        Databuffer_mockup(string);
        ~Databuffer_mockup() {};
        void set_filepath(string);
        string get_filepath() const;
        int getfile_size() const;
        void delete_file();
};
