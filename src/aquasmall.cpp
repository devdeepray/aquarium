#include <simplecpp>
#include <ctime>
#include <cstdlib>
#define np 50
#include "fishfuncts.h"
#include "canvasdesign.h"
#include "bblset.h"
#include "grass.h"
#include <sstream>
#include "misc.h"
#include "picture.h"
int main() {


    int curfish = 0;
    unsigned int tim = time ( NULL );	//for Seeding randomness
    double darkness; //for the day night;
    int timesteps = 40000;//Variable for simulated time
    canvas::srand ( tim ); //seeding srand
    int htime = 0;
    int numFishes = 50;//Maximum number of fishes
    bool hungry = false;//If any fish is hungry
    bool showhunger = false;//If hunger bars to be shown
    bool cont;//continue or new aquarium
    initCanvas ( "c", 900, 700 ); //open a drawable of 900X700
    pic();
    textbox textDisplay;//define a textbox struct
    Text timetext;//a text for the time
    beginFrame();//Stop updating drawable tillentire frame has been changed.
    //new aqua or continue screen shown here
    beginFrame();
    Rectangle clip ( 450, 350, 900, 700 );
    clip.setFill ( true );
    clip.setColor ( COLOR ( 255, 255, 255 ) );
    clip.imprint();
    clip.hide();
    endFrame();

    button ( 400, 350, 80, 60, "Continue" ); //two buttons.
    button ( 500, 350, 80, 60, "New Aquarium" );
    endFrame();
    while ( 1 ) { //check which button.
            int clickx = getClick();
            int clicky = clickx % 65536;
            clickx /= 65536;
            if ( clickx > 360 && clickx < 540 && clicky < 350 && clicky > 290 ) {
                    cont = clickx < 450;
                    break;
                }
        }



    beginFrame();
    drawArtifacts();			//make buttons.
    drawfishes();//imprint fish on buttons.
    watersurface w;		//upper water surface.
    fishy f[numFishes];			//array of fishes.
    bblset b1 ( 100 );				//3 sets of bubbles.
    bblset b2 ( 400 );
    bblset b3 ( 700 );
    food fishfood;				//fish food struct.
    XEvent event;				//Xlib event handler instance.
    grass g3 ( 30 );				//4 sets of grass.
    grass g2 ( 20 );
    grass g1 ( 10 );
    grass g0 ( 0 );
    //clipping rectangle as grass could show outside.
    clip.reset ( 805, 300, 10, 600 );
    clip.show();
    clip.setColor ( COLOR ( 255, 255, 255 ) );

    clip.setFill ( true );

    if ( cont ) { //if user continues
            fromfile ( f, numFishes, timesteps );	//get the saved simulation time.
        }
    //get stored fish data from file.
    for ( int i = 0; i < numFishes; i++ ) {
            f[i].initFish ( cont, 0 ); //initialize all fishes.used function rather than constructor.
            if ( f[i].life ) f[i].resurrectFish(); //show alive fishes.
            else    f[i].killFish();	//give dead values to dead fishes.
        }

    for ( ;; ) {				//main program loop.

            darkness = 0.9 * sine ( 180.0 * timesteps / 86400.0 ) * sine ( 180.0 * timesteps / 86400.0 ) + 0.1;
            beginFrame();
            nextEvent ( &event );		//check for next event.
            if ( htime < 50 ) {		//show hunger bars for 50 iterations.
                    htime++;
                }
            else {
                    showhunger = false;
                }
            if ( checkEvent ( &event ) ) { //if click, then execute this body.
                    if ( event.type == ButtonPress && event.xmotion.x > 800 ) { //if clicked on some button.
                            int button = checkbutton ( event.xmotion.y ); //check which button was pressed.

                            if ( button <= 4 ) { //if new fish.
                                    addFish ( f, numFishes, button );
                                    textDisplay.newtext ( "You bought a new fish :)Take good care!" );
                                    curfish++;
                                }
                            else {
                                    switch ( button ) {
                                            case 5: {//feed fish
                                                    givefood ( f, fishfood, numFishes, &hungry );
                                                    if ( curfish == 1 )
                                                        textDisplay.newtext ( "Gulp gulp. Your fish is full :)" );
                                                    if ( curfish > 1 )
                                                        textDisplay.newtext ( "Gulp gulp. Your fish are full :)" );

                                                    break;
                                                }
                                            case 6: {//show hunger bars
                                                    showhunger = true;
                                                    htime = 0;
                                                    break;
                                                }
                                            case 7: {//pause simulation.
                                                    textDisplay.newtext ( "Simulation paused. Get your coffee and be back fast!" );
                                                    endFrame();
                                                    while ( 1 ) {
                                                            int click = getClick();
                                                            if ( click / 65536 > 800 &&
                                                            checkbutton ( click % 65536 ) == 7 ) break;
                                                        }
                                                    beginFrame();
                                                    textDisplay.newtext ( "Simulation running." );
                                                    break;
                                                }
                                            case 8: { //reset aquarium.
                                                    aquareset ( f, numFishes, textDisplay );
                                                    curfish = 0;
                                                    for ( int i = 0; i < 400; i++ )
                                                        fishfood.foodmove();//remove fish
                                                    //food from screen.
                                                    break;
                                                }
                                            case 9: {//quit.
                                                    quit ( f, numFishes, timesteps ); //save file.
                                                    goto out;//exit main execution loop
                                                }
                                        }
                                }
                        }
                    else if ( event.type == ButtonPress ) { //click on the aquarium
                            for ( int i = 0; i < numFishes; i++ ) //make fishes flee.
                                f[i].goaway ( event.xmotion.x, event.xmotion.y );
                        }
                }
            if ( !hungry ) { //check if fishes are hungry.
                    if ( ( hungry = checkHungry ( f, numFishes ) ) ) {
                            textDisplay.newtext ( "!!!Feed your fish :(!!!" );
                        }
                }
            if ( checkDeath ( numFishes, f, hungry ) ) { //check if a fish died.
                    curfish--;
                    textDisplay.newtext ( "A fish died... may its soul rest in peace." );
                }
            fishfood.foodmove();//give signal to the food struct. It will move if it has to.
            w.morph ( darkness );
            b1.bubbleSetMotion();//give a step signal to the bubble structs.
            b2.bubbleSetMotion();
            b3.bubbleSetMotion();
            paintScr ( darkness ); //paint water and sand.
            pebbles ( 100, 550, darkness ); //paint stones.
            pebbles ( 430, 560, darkness );
            g3.swayStep ( darkness ); //give signal to grass to sway one step.
            g2.swayStep ( darkness );
            g1.swayStep ( darkness );
            g0.swayStep ( darkness );

            for ( int i = 0; i < numFishes; i++ ) { //move the fish.
                    if ( f[i].life )
                        f[i].rm ( showhunger , darkness ); //give a signal to fish to move one step.
                }
            showclock ( timesteps, timetext ); //update the clock.
            endFrame();//update the canvas.
            usleep ( 14000 ); //wait. Limits max frame rate to 100;
            timesteps += 10;//increase simulation time by one step(1 min)
            timesteps %= 86400;//wrap around timesteps.
        }
out:
    ;

}



