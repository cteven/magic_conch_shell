#include "test/Databuffer_mockup.h"


Databuffer_mockup::Databuffer_mockup(string path) : file_size(0), filepath(path)
{}


void Databuffer_mockup::set_filepath(string path)
{
    filepath = path;
}

std::string Databuffer_mockup::get_filepath() const
{
    return filepath;
}

int Databuffer_mockup::getfile_size() const
{
    return file_size;
}

void Databuffer_mockup::delete_file()
{
    // do nothing because we do not actually use a file here
}
