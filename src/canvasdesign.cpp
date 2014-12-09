#include <simplecpp>
#include "canvasdesign.h"
void button ( double cx, double cy, double width, double height, string text ) {//makes the rhs buttons.
    Rectangle buttonBorder ( cx, cy - 28, width, height );//makes the button with text in it.
    buttonBorder.imprint();
    buttonBorder.setColor ( COLOR ( "white" ) );
    buttonBorder.setFill ( true );
    buttonBorder.imprint();
    Text buttonText ( cx, cy - 28, text );
    buttonText.imprint();
}
void paintScr ( double &darkfac ) {//paints the canvas and its brightness depends on simtime.


    Rectangle waterStripe ( 400, 30, 800, 10 );//water painted using rectangle strips.
    waterStripe.setFill ( true );
    for ( int i = 6; i < 106; i+=2 ) {//move and imprint the stripe.
            waterStripe.setColor ( COLOR ( ( 200 - ( i * 200 ) / 160 )
                                           *darkfac, ( 200 - ( i * 200 ) / 160 ) *darkfac, 230 * darkfac ) );
            waterStripe.imprint();
            waterStripe.move ( 0, 10 );
        }
    Rectangle sandStripe ( 0, 800, 0, 700 );//stripe for the sand.
    sandStripe.setFill(true);
    for ( int i = 0; i < 800; i+=5 ) {//paint the sand.
            sandStripe.reset ( i+2, 550+5*sine(i), 5, 100- 10 * sine ( i ) );
            sandStripe.setColor ( COLOR ( ( 200 - 30 * sine ( i ) )
                                          *darkfac, ( 200 - 30 * sine ( i ) ) *darkfac, 0 ) );
            sandStripe.imprint();
        }
}
void pebbles ( int x, int y, double &darkfac ) {//pebbles.
    x -= 99;
    y -= 341;

    int stoneSetting[19][2] = {{99, 322}, {150, 319}, {210, 310},//a good looking arrangement of pebbles.
        {248, 326}, {272, 326}, {295, 307}, {179, 326},
        {126, 335}, {97, 338}, {153, 341}, {197, 340}, {219, 335},
        {175, 343}, {255, 339}, {281, 337},
        {308, 332}, {65, 341}, {326, 340}, {294, 341}
    };
    double r = 20;
    Line pebbleStripe;//line that is imprinted with a gradient and varying height to make an ellipse.
    for ( int j = 0; j < 19; j++ ) {
            double cx = stoneSetting[j][0] + x;
            double cy = stoneSetting[j][1] + y;
            for ( int i = -r; i < r; i++ ) {
                    pebbleStripe.reset ( cx + i, cy - 0.8 * ( sqrt ( r * r - i * i ) ), cx + i, cy + 0.8 *
                                         ( sqrt ( r * r - i * i ) ) );
                    pebbleStripe.setColor ( COLOR ( sqrt ( ( i + r ) / ( 2 * r ) ) * ( 238 ) *darkfac,
                                                    sqrt ( ( i + r ) / ( 2 * r ) ) * ( 232 ) *darkfac,
                                                    sqrt ( ( i + r ) / ( 2 * r ) ) * ( 170 ) *darkfac ) );
                    pebbleStripe.imprint();
                }
        }
}
void drawArtifacts() {//draw all the buttons.
    button ( 850, 60, 80, 50, "" );
    button ( 850, 120, 80, 50, "" );
    button ( 850, 180, 80, 50, "" );
    button ( 850, 240, 80, 50, "" );
    button ( 850, 300, 80, 50, "" );
    button ( 850, 360, 80, 50, "Food       " );
    button ( 850, 420, 80, 50, "Show Hunger" );
    button ( 850, 480, 80, 50, "Pause/Play " );
    button ( 850, 540, 80, 50, "Reset      " );
    button ( 850, 600, 80, 50, "Quit       " );
}

watersurface::watersurface(){//upper water surface.
    points[0][0]=0;//end points.
points[0][1]=30;
r.reset(400,20,800,40);//the white rectangle that wipes previous image.
r.setColor(COLOR(255,255,255));
r.setFill(true);
p.setFill(true);
p.setColor(COLOR(192,192,230));
    points[20][0]=800;
points[20][1]=30;
for(int i=0;i<19;i++){
heightvar[i]=randuv(5,10);//max height variation for a point.
phase[i]=randuv(0,360);//phase of undulation.
}
}

void watersurface::morph(double &darkfac)//morph the water surface
{
    for(int i=1;i<=19;i++)
    {
        points[i][0]=44.44*(i-1)+10*sine(phase[19-i]);
        points[i][1]=20+heightvar[i-1]*sine(phase[i-1]);
        phase[i-1]+=randuv(6,8);
    }

    r.show();
    r.imprint();
    r.hide();
    p.show();
    p.reset(0,0,points,21);
    p.setFill(true);
p.setColor(COLOR(192*darkfac,192*darkfac,230*darkfac));
p.imprint();
p.hide();

}





