#include "Cord.h"

unsigned int Cord::getcord_pull() const { return cord_pull; }

void Cord::set_cord_pull(int pull) {
    if( pull > 100 ) pull = 100;
    cord_pull = pull;
}
