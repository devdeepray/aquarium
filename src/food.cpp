#include <simplecpp>
#include "food.h"
food::food() {//food constructor that gives garbage position outside screen and sets random colors.
    for ( int i = 0; i < 100; i++ ) {
            fposition[i][0] = -100;
            fposition[i][1] = -100;
            C[i].reset ( fposition[i][0], fposition[i][1], 3 );
            C[i].setColor ( COLOR ( randuv(0,255),
                                   randuv(0,255), randuv(0,255) ) );
            C[i].setFill();
            C[i].hide();
        }
    f = 400;
}
void food::foodreset() {//when food is given, this activates foodmove by setting f=0. also unhides food.
    if ( f >= 400 ) {
            for ( int i = 0; i < 100; i++ ) {
                    fposition[i][0] = randuv ( 0.0, 790.0 );
                    fposition[i][1] = randuv ( 0.0, 200 );
                    C[i].show();
                }
            f = 0;
        }
}
void food::foodmove() {//moves food by one step. with random x vibrations.
    if ( f < 400) {
            for ( int i = 0; i < 100; i++ ) {
                    fposition[i][1]++;
                    fposition[i][0] += randuv ( -1.0, 1.7 );
                    C[i].moveTo ( fposition[i][0] , fposition[i][1] );
                    C[99*f/400].hide();
                }
            f++;
        }
    else {
            for ( int i = 0; i < 100; i++ ) C[i].hide();

        }
}

