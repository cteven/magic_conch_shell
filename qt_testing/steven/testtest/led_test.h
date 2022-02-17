#ifndef LED_TEST_H
#define LED_TEST_H

#include <QWidget>

class led_test : public QWidget
{
    Q_OBJECT

private:
    bool state;
public:
    explicit led_test(QWidget *parent = nullptr);
    void toggle();

protected:
    void paintEvent(QPaintEvent *);

};

#endif // LED_TEST_H
