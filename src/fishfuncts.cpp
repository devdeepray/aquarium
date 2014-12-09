#include <simplecpp>
#include "fishfuncts.h"
int searchEmpty ( fishy * f1, const int & n ) {//searches for a dead fish to replace with a new fish.
    for ( int i = 0; i < n; i++ ) {
            if ( !f1[i].life ) return i;
        }
    return -1;
}
void addFish ( fishy * f, const int & numFishes, const int & button ) {//adds a new fish.
    int emptyPos = searchEmpty ( f, numFishes );
    if ( emptyPos >= 0 ) {
            f[emptyPos].initFish ( false, button );
            f[emptyPos].resurrectFish();
        }
}
void drawfish ( int fishtype, int x, int y, float scale ) {//imprints fish(for buttons.)
    fishy fish;
    fish.initFish ( false, fishtype );
    fish.p.setScale ( scale );
    fish.p.show();
    fish.p.moveTo ( x, y );
    fish.p.imprint();

}
void drawfishes() {//uses drawfish to draw all five fishes.
    drawfish ( 0, 835, 32, 1 );
    drawfish ( 1, 835, 92, 1 );
    drawfish ( 2, 835, 156, 1 );
    drawfish ( 3, 845, 200, 0.7 );
    drawfish ( 4, 840, 272, 0.9 );
}
void aquareset ( fishy * f, const int & n, textbox & tdpy ) {//resets the aquarium
    for ( int i = 0; i < n; i++ ) {
            f[i].life = false;
            f[i].killFish();
        }
    tdpy.newtext ( " " );
    tdpy.newtext ( "  " );
    tdpy.newtext ( "   " );

}

void quit ( fishy * f, const int & n, const int & time ) {//exits after saving to file.
    ofstream out ( "state.save" );
    out<<time<<" ";
    for ( int i = 0; i < n; i++ ) {
            out << f[i].life << " " << f[i].ftype << " " << f[i].agemax << " " << f[i].age << " " << f[i].maxhunger << " " << f[i].hunger << " " << f[i].scale << " ";
        }
}

void fromfile ( fishy * f,int &n,int &t ) {//gets data about fishes from file.
    ifstream in ( "state.save" );



    in >> t;//gets time.

    for ( int i = 0; i < n; i++ ) {
            in >> f[i].life >> f[i].ftype >> f[i].agemax >> f[i].age >> f[i].maxhunger >> f[i].hunger >> f[i].scale;
        }
}

void givefood ( fishy * f, food & fishfood, int & numFishes, bool * hungry ) {//triggers food struct.

    fishfood.foodreset();
    hungerReset ( numFishes, f );//make all fishes full.
    hungry = false;
}
bool checkHungry ( fishy * f, int & numFishes ) {//checks if any fish is hungry. returns true if found.
    for ( int i = 0; i < numFishes; i++ ) {
            if ( ( f[i].hunger > (2.0/3)*f[i].maxhunger ) ) return true;
        }
    return false;
}


bool checkDeath ( int & numFishes, fishy * f, bool & hungry ) {//checks if any fish is dying.
    bool dead = false;
    for ( int j = 0; j < numFishes; j++ ) {
            if ( ( f[j].hunger > f[j].maxhunger * 2 ) || ( f[j].age > f[j].agemax ) ) {

                    f[j].killFish();//kills concerned fish.
                    dead = true;
                    hungry = false;
                }
        }
    return dead; //returns true if any fish found dead during run.
}
