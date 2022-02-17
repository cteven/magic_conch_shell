#pragma once

#include <vector>
#include <string>
#include "Databuffer.h"


using namespace std;

class FileInfoCollector_mockup
{
private:
    std::vector<Databuffer *> buffers;
    int buflen;

public:
    void save_file(std::string);
    std::string get_filepath() const;
    int getfile_size() const;
    void pop_back();
    void remove(Databuffer *);
    void remove(std::string);
    // Databuffer * searchDatabuffer(std::string);
};
