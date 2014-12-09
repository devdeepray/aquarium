#include "misc.h"
int checkbutton ( int y ) {//checks which button was pressed.
    return ( y - 7 ) / 60;
}
string inttostring ( int a ) {//converts int to string. ****no idea how it works. Picked it up from the net.
    return static_cast<ostringstream*> ( & ( ostringstream() << a ) )->str();
}

void showclock ( int timestep, Text & hrs ) {//display the clock.
    string a;
    timestep += 10000; //adjust according to the darkness/lightness
    timestep %= 86400;
    a = inttostring ( ( ( timestep + 82800 ) / 3600 ) % 12 + 1 ) + ":" + inttostring ( ( timestep % 3600 ) / 60 );
    if ( timestep < 43200 ) a = a + "AM";
    else a = a + "PM";
    hrs.reset ( 40, 650, a );
}





