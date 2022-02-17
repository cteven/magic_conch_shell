#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->kordel->setMaximum(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_kordel_valueChanged(int value)
{
    qDebug() << ui->kordel->value();

    if(60 <= value  || (!(ui->kordel->isSliderDown()) && 60 <= value))
    {
        qDebug() << ui->kordel->value();
        ui->kordel->setValue(0);
    }
}

void MainWindow::on_kordel_sliderReleased()
{
    qDebug() << "released" << ui->kordel->value();

}



