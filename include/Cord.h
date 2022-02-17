#pragma once

#include <QObject>

class Cord : public QObject {
private:
    unsigned int cord_pull;

public:
    Cord() : cord_pull(0) {};
    unsigned int getcord_pull() const;


public slots:
    void setcord_pull(int);
};
