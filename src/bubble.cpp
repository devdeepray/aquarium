#include <simplecpp>
#include "bubble.h"
bubble::bubble() {//constructor that initializes bubbles with random sizes and hidden.
    bblx = -200;
    bbly = randuv ( 0, 590 );
    size = randuv ( 1, 11 );
    bbl.reset ( bblx, bbly, size );
    bbl.setColor ( COLOR ( 255, 255, 255 ) );
}
void bubble::bubbleMotion() {//moves a bubble by one step when called.
    bblx += ( 3.0 / size ) * ( randuv ( -1, 1 ) );//x random vibration inversly proportional to size.
    if ( bbly < 0 ) {
            bbly = 590;//if bubble goes up, bring it back to bottom.
            bblx = x + randuv ( 0, 50 );
            size = randuv ( 1, 11 );//give it a new size.
            bbl.reset ( bblx, bbly, size );
            bbl.setColor ( COLOR ( 255, 255, 255 ) );
        }
    bbly -= 5.0 / log ( size+2 );//y velocity inversely proportional to size.
    bbl.reset ( bblx, bbly, size );//move bubble.
}
