#include "led_test.h"
#include <QPainter>
#include <QDebug>

led_test::led_test(QWidget *parent) : QWidget(parent), state(false) {
    setFixedSize(30,30);
    //repaint();

}

void led_test::paintEvent(QPaintEvent *) {
    QPainter led(this);

    Qt::GlobalColor color = state ? Qt::red : Qt::green;
    led.setBrush(QBrush(color, Qt::SolidPattern));
    led.drawEllipse(0,0,20,20);

    qDebug() << "setting led to" << color;
}

void led_test::toggle() {
    state = !state;
    repaint();
}
