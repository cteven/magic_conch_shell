#include "test/FileInfoCollector_mockup.h"

void FileInfoCollector_mockup::save_file(string path)
{

}

string FileInfoCollector_mockup::get_filepath() const
{
    return "path";
}

int FileInfoCollector_mockup::getfile_size() const
{
    return 0;
}

void FileInfoCollector_mockup::pop_back()
{}

void FileInfoCollector_mockup::remove(Databuffer * buf)
{}

void FileInfoCollector_mockup::remove(string)
{}

/*
Databuffer *FileInfoCollector_mockup::searchDatabuffer(string path)
{}
*/
