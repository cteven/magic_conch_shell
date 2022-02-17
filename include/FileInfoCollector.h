#pragma once

#include <vector>
#include <string>

#include "Databuffer.h"

using namespace std;

class FileInfoCollector
{
private:
    vector<Databuffer *> buffers;
    int buflen = 0;

public:
    void save_file(string);
    string get_filepath() const;
    int getfile_size() const;
    void pop_back();
    void remove(string);

//    void remove(Databuffer *);
//    Databuffer * searchDatabuffer(std::string);
// maybe an add_files_from_directory(string dirname) function needed if we use local audiofiles
};
