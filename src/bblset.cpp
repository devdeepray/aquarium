#include <simplecpp>
#include "bblset.h"
bblset::bblset ( int xMin ) {//constructor that initializes all bubble structs
    for ( int i = 0; i < 20; i++ )
        b[i].x = xMin;
}
void bblset::bubbleSetMotion() {//make all bubbles move by one step.
    for ( int i = 0; i < 20; i++ )
        b[i].bubbleMotion();
}
