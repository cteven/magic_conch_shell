#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QMessageBox>
#include <QGridLayout>

#include "led_test.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow( QString haja, QWidget *parent = nullptr);
    ~MainWindow();

public:

private slots:
      void toggle_image();


      void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *image;
    QMessageBox display_message;
    QString message;

    led_test *led1_;


};
#endif // MAINWINDOW_H
