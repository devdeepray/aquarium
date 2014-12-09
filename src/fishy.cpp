#include <simplecpp>
#include "fishy.h"
#define np 50
void hungerReset(int size, fishy * f) {//resets hunger of all fishes.
  for(int i = 0; i < size; i++) {
      f[i].hunger = 0;
      f[i].hungerbar2.setColor(COLOR("green"));
    }
}
void fishy::killFish() {//hides all fish things
  hungerbar1.hide();//hides hunger bars initially. not necessary later.
  hungerbar2.hide();
  p.hide();
  life = false;
}
void fishy::resurrectFish() {//shows the fish.
  p.show();//shows the fish.
  life = true;
}
void fishy::initFish(bool cont, short fishtype) {//initalizes fish.
  double shapedef[5][np][2] = {//five fish shapes.
    { { -59, 0}, { -54, -4}, { -44, -6}, { -30, -8}, { -18, -8}, { -6, -23}, {4, -45}, {28, -63}, {64, -74}, {35, -62},
      {25, -54}, {18, -41}, {31, -38}, {54, -51}, {72, -61}, {58, -47}, {50, -40}, {41, -34}, {56, -24}, {69, -14},
      {85, -12}, {93, -25}, {115, -44}, {157, -61}, {140, -43}, {115, -23}, {122, -12}, {146, -11}, {166, -13},
      {162, -1}, {141, 2}, {123, 4}, {127, 12}, {147, 15}, {162, 24}, {155, 32}, {132, 29}, {113, 21}, {92, 8},
      {76, 13}, {64, 23}, {49, 27}, {45, 39}, {52, 49}, {76, 71}, {81, 79}, {69, 77}, {43, 64}, {28, 44}, {4, 28}
    },
    { { -47, 0}, { -37, -11}, { -25, -19}, { -11, -22}, {2, -25}, {10, -35}, {18, -42}, {28, -46}, {24, -36}, {19, -26},
      {35, -23}, {46, -31}, {52, -35}, {49, -26}, {46, -20}, {56, -16}, {70, -11}, {81, -8}, {90, -9}, {112, -15},
      {128, -19}, {138, -19}, {132, -12}, {122, -5}, {114, 5}, {124, 11}, {136, 20}, {138, 25}, {112, 16}, {101, 11},
      {83, 5}, {66, 7}, {52, 14}, {35, 18}, {33, 26}, {37, 35}, {28, 34}, {18, 28}, {11, 17}, { -4, 15}, { -20, 11},
      { -33, 9}, { -46, 1}, { -46, 2}, { -46, 2}, { -46, 2}, { -46, 2}, { -46, 2}, { -46, 2}, { -46, 2}
    },
    { { -58, 0}, { -56, -7}, { -47, -10}, { -39, -21}, { -32, -37}, { -24, -55}, { -6, -62}, {14, -67}, {33, -68}, {61, -67},
      {79, -63}, {65, -59}, {81, -53}, {90, -42}, {95, -28}, {107, -24}, {114, -33}, {124, -48}, {135, -52}, {136, -45},
      {126, -26}, {123, -10}, {131, 8}, {141, 19}, {136, 25}, {127, 23}, {117, 13}, {107, 1}, {100, -2}, {95, 13}, {89, 23},
      {77, 31}, {57, 35}, {35, 38}, {13, 35}, { -9, 29}, { -29, 17}, { -36, 4}, { -46, 1}, { -46, 1}, { -46, 1}, { -46, 1}, { -46, 1},
      { -46, 1}, { -46, 1}, { -46, 1}, { -46, 1}, { -46, 1}, { -46, 1}, { -46, 1}
    },
    {
      { -36, 14}, { -44, 11}, { -41, 0}, { -27, -9}, { -15, -21}, { -11, -40}, { -16, -46}, { -4, -42}, {0, -51}, {5, -39}, {22, -45},
      {15, -34}, {31, -32}, {22, -26}, {37, -21}, {28, -13}, {40, 1}, {27, 0}, {27, 14}, {23, 30}, {21, 45}, {20, 66}, {23, 94},
      {25, 111}, {35, 134}, {52, 141}, {72, 132}, {63, 114}, {53, 120}, {62, 106}, {79, 117}, {86, 136}, {65, 153}, {28, 156},
      {10, 139}, { -11, 116}, { -24, 94}, { -32, 68}, { -24, 43}, { -5, 28}, {2, 12}, { -1, -1}, { -12, -3}, { -24, 6}, { -36, 13},
      { -36, 13}, { -35, 13}, { -35, 13}, { -35, 13}, { -35, 13}
    },
    {
      { -39, 1}, { -27, -15}, { -12, -29}, {12, -42}, {38, -50}, {27, -38}, {23, -30}, {42, -29}, {55, -26}, {78, -38},
      {95, -41}, {79, -29}, {71, -20}, {84, -10}, {96, -1}, {110, -6}, {122, -12}, {139, -15}, {124, -1}, {124, 7},
      {133, 17}, {143, 20}, {123, 18}, {112, 14}, {101, 8}, {97, 6}, {90, 11}, {74, 17}, {62, 21}, {44, 22}, {47, 32},
      {52, 38}, {63, 45}, {45, 42}, {34, 38}, {27, 33}, {21, 25}, {9, 20}, { -7, 16}, { -21, 12}, { -31, 8}, { -38, 2},
      { -37, 0}, { -36, 1}, { -36, 1}, { -36, 1}, { -36, 1}, { -36, 1}, { -36, 0}, { -36, 0}
    }
  };
  double velocitydef[5] = {0.8, 1, 0.9, 0.2, 0.7};//velocities of diff fishes.

  double agedef[5] = {40000, 60000, 80000, 100000, 50000};//ages of fishes.
  short coldef[5][3] = {{0 + randuv(0, 60), 255 + randuv(-60, 0), 127 + randuv(-30, 30) }, {255 + randuv(-50, 0),
   255 + randuv(-40, 0), randuv(0, 50) }, {255 + randuv(-60, -20), 69 + randuv(-30, 30), randuv(0, 50) },
   {200 + randuv(-40, 20), 200 + randuv(-30, 30), 0}, {randuv(0, 60), 0, 200 + randuv(-30, 30) }};//colors of fish.
  if(!cont) {//variables necessary of not continuing. If continue, values got from file.
      ftype = fishtype;//type of fish
      life = false;
      agemax = agedef[fishtype] + randuv(0, 10000);//fish age with random component.
      maxhunger = randuv(10000, 12000);//maximum hunger with random component.
      hunger = 0;
      scale = 1;//size.
      age = 1;//age.
    }
  ky = -1; //y direction.
  kxprev = 1;//previous x direction.
  kx = -1;//x direction.
  dx = 10000;//fast x velocity variable.
  dy = 10000;//fast y velocity variable.
  x = prevalx = valx = randuv(50, 750);//initial x position.
  y = valy = prevaly = randuv(50, 460);//initial y position.
  vel = velocitydef[fishtype] + randuv(-0.2, 0.2);//velocity of fish with random component.
  fishcol = COLOR(coldef[ftype][0], coldef[ftype][1], coldef[ftype][2]);//color of fish with random component.
  col[0]=coldef[ftype][0];
  col[1]=coldef[ftype][1];
  col[2]=coldef[ftype][2];
  hungerbar1.reset(x, y - 50, 50, 10);
  hungerbar2.reset(x - 22.5, y - 50, 0, 6);
  hungerbar1.setColor(COLOR("black"));
  hungerbar2.setColor(COLOR("green"));
  hungerbar2.setFill(true);
  for(int m = 0; m < np; m++)
    for(int q = 0; q < 2; q++) {//scale down original coordinates.
        if(ftype != 3)
          shape[m][q] = shapedef[ftype][m][q] / 4;
        else
          shape[m][q] = shapedef[ftype][m][q] / 3;
        xc[m] = shape[m][0];
      }
  p.reset(x, y, shape, np);
  p.setFill(true);
  p.setColor(fishcol);
  flipc = 10;//vriable for flipping action set so that no flip at start.
  hungerbar1.hide();
  hungerbar2.hide();
}
void fishy::goaway(int xpos, int ypos) {//quick run away function.
  if(abs(x - xpos) < 100 && abs(y - ypos) < 100) {//if fish is near vicinity, then make it run away.
      if(x - xpos != 0 && &y - ypos != 0) {
          if(kx != (x - xpos) / abs(x - xpos))
            flipc = 10 - flipc;//set flip if fish is coming close to pointer.
          kx = (x - xpos) / abs(x - xpos);//set run away direction in x.
          ky = (y - ypos) / abs(y - ypos);//set run away direction in y.
        }
      dx = 1;//variable velocity component dx reduced as velocity is inversely proportional.
      dy = 1;//ditto in y.
      if(kx > 0)//set new position, but not outside aquarium.
        valx = min(x + 100, 750.0);
      else
        valx = max(x - 100, 50.0);
      if(ky > 0)
        valy = min(y + 100, 500.0);
      else
        valy = max(y - 100, 60.0);
    }
}
void fishy::rm(bool showhunger,double & darkfac) {
  double vact = 15.0 * vel / dx + vel;//actual velocity with variable and constant component.
  if(flipc < 10) {//if fish is flipping, perform the following.
      for(int i = 0; i < np; i++)//invert all x coordinates.
        shape[i][0] -= (kx * xc[i]) / 5;
      flipc++;//flipc is count for how many times flip algo will run before continuing with linear motion.
      x += -2 * vel * kx * (5.0 - flipc) / 10;//changes x coord while flipping for more natural motion.
      p.reset(x, y, shape, np);
      p.setFill(true);
      p.setColor(fishcol);
    }
  else {//normal motion.
      if((x > valx && kx == 1) || (x < valx && kx == -1)) {//if fish has reached valx which was its destination, set a new destination.
          prevalx=valx;
          do {
              valx = randuv(30, 700);//set new destination randomly.
            }
          while(abs(valx - prevalx) < 50);//take care that new and current positions are ot too close.
          kxprev = kx;
          if(valx - prevalx > 0)//decide new direction.
            kx = 1;
          else kx = -1;
          if(kxprev * kx < 0) {//decide whether to flip.
              flipc = 0;

            }
            dx=1;//set fast motion. Whether it flips or doesnt.

        }
      else {
          x += vact * kx;
          p.move(vact * kx, 0);
          dx++;
        }
    }
  if((y > valy && ky == 1) || (y < valy && ky == -1)) {//same thing for y. only no flipping.
      prevaly = valy;
      if(ftype!=3)//if not sea horse.
      valy = randuv(60, 460);
      else valy=randuv(400,500);//if sea horse.
      if(valy - prevaly > 0)
        ky = 1;
      else ky = -1;
    }
  else {
      y += ky * (20.0 / dy + 1 / 5.0);
      p.move(0, ky*(20.0 / dy + 1 / 5.0));
      dy++;
    }
  scale = 1+(float)(age)/agemax;//grow fish.
  p.setScale(scale);
  p.setColor(COLOR(col[0]*darkfac,col[1]*darkfac,col[2]*darkfac));
  age += 1;//increment age.
  hunger += 2;//increment hunger.
  if(showhunger && hunger < maxhunger) {//set hunger bars only if hunger bar is to be shown.
      hungerbar1.reset(x, y - scale * 30, 50, 10);
      hungerbar2.reset(x - 22.5 + hunger * 22.5 / maxhunger, y - scale * 30, (int)(hunger * 45.0 / maxhunger), 6);
    }
  else if(showhunger){
      hungerbar1.reset(x, y - scale * 30, 50, 10);
      hungerbar2.reset(x, y - scale * 30, 45, 6);
    }
  if(showhunger && hunger > 2 * maxhunger / 3.0) {

      hungerbar2.setColor(COLOR("red"));
    }
  if(!showhunger) {// hide hunger if it is not to be shown.
      hungerbar1.hide();
      hungerbar2.hide();
    }


}





