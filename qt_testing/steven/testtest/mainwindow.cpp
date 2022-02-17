#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QPixmap>


#define BHTPIX "../testtest/bht.png"
#define BEUTHPIX  "../testtest/beuth.png"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    led1_ = new led_test();
    ui->setupUi(this);
    ui->gridLayout->addWidget(led1_);



    this->image = findChild<QLabel* >("bht");
    image->setToolTip("bht");
    image->setAlignment(Qt::AlignCenter);

    qDebug() << "window-size is " << this->width() << " x " << this->height();
    qDebug() << "boggle-size is " << this->image->width() << " x " << this->image->height();

    connect(ui->toggleButton, SIGNAL(clicked()), this, SLOT(toggle_image()));

}

MainWindow::MainWindow(QString haja, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , message(haja)
{
    ui->setupUi(this);
    ui->gridLayout->addWidget(led1_);

    led1_ = new led_test();

    this->image = findChild<QLabel* >("ronaldmcboggle");
    image->setToolTip("boggle");
    image->setAlignment(Qt::AlignCenter);

    qDebug() << "window-size is " << this->width() << " x " << this->height();
    qDebug() << "boggle-size is " << this->image->width() << " x " << this->image->height();

    connect(ui->toggleButton, SIGNAL(clicked()), this, SLOT(toggle_image()));
    connect(ui->pushButton, SIGNAL(clicked()), led1_, SLOT(set_let()));

    display_message.setIcon(QMessageBox::NoIcon);
    display_message.setText(haja);
    display_message.setStandardButtons(QMessageBox::Ok);
    display_message.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggle_image() {
    qDebug() << "current toolTip: " << this->image->toolTip();
    QPixmap pix(BHTPIX);


    if(this->image->toolTip() == "bht") {
        image->setToolTip("beuth");
        if (!pix.load(BEUTHPIX)) qDebug() << "pix not loaded";
        this->image->setPixmap(pix);
    }
   else {
        image->setToolTip("bht");
        this->image->setPixmap(pix);
   }
}



void MainWindow::on_pushButton_clicked()
{
    qDebug() << "pushed";
    led1_->toggle();
}

