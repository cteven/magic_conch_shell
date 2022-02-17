#include "mainwindow.h"
#include "led_test.h"

#include <QApplication>
#include <QString>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    //QString test = "Testing QMessageBox";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
