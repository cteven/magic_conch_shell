#include "Databuffer.h"
#include <QFile>
#include <QString>
#include <QDebug>

using namespace std;

Databuffer::Databuffer(string path): file_size(0), filepath(path) {
    QFile file(QString::fromStdString(filepath));

    qDebug() <<"buffer" <<file.exists();

    if(file.exists())
        file_size = file.size();
    else
        filepath.clear();

    qDebug() << QString::fromStdString(filepath);
}

Databuffer::~Databuffer() {
    delete_file();
}

string Databuffer::get_filepath() const { return filepath; }

void Databuffer::set_filepath(string path) {

    QFile file(QString::fromStdString(path));

    if(file.exists()) {
        filepath = path;
        file_size = file.size();
    }
    else
        filepath.clear();
}

int Databuffer::getfile_size() const { return file_size; }

void Databuffer::delete_file() {
    QFile file(QString::fromStdString(filepath));
    if(file.exists()){
        file.remove();
    }

}
