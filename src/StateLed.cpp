#include "StateLed.h"
#include <QDebug>

int StateLed::getstate(){
    return state_;
}

void StateLed::resetstate()
{
    qDebug() << "StateLed: Idle";
    state_ = kIdle;
}

void StateLed::setstate(state new_state) {
    switch(new_state) {
        case 0:
            qDebug() << "StateLed: Idle";
            break;
        case 1:
            qDebug() << "StateLed: Listening";
            break;
        case 2:
            qDebug() << "StateLed: Analysing";
            break;
        case 3:
            qDebug() << "StateLed: Replying";
            break;
    }
    state_ = new_state;
}
