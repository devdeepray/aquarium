#include "picture.h"
void pic() {
    Rectangle r ( 1, 1, 1, 1 );
    r.setFill ( true );

    beginFrame();
    for ( int j = 0; j < 800; j++ ) {
        r.setColor(COLOR(255*sine((j/800.0)*180)*sine((j/800.0)*180),255*sine((j/800.0)*180+120)*sine((j/800.0)*180+120),255*sine((j/800.0)*180+240)*sine((j/800.0)*180+240)));
            for ( int i = 0; i < 1000; i += 8 ) {

                    r.moveTo ( i + 8 - 50, j - 50 );


                    for ( int k = 7; k >= 0; k-- ) {
                            if ( ( img[125*j+i/8] / ( int ) pow ( 2, k ) ) % 2 == 1 ) r.imprint();
                            r.move ( -1, 0 );
                        }




                }
        }
    endFrame();
    wait ( 4 );
}













