#include "Cord.h"

unsigned int Cord::getcord_pull() const { return cord_pull; }

void Cord::setcord_pull(int pull) {
    if( pull > 100 ) pull = 100;
    cord_pull = pull;
}

