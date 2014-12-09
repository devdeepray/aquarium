#include <simplecpp>
#define np 50
struct fishy {
  int hunger, valx, valy, kx, ky, kxprev, prevalx, prevaly, flipc, ftype, dx, dy;// variable declarations
  bool life;//dead or alive.
  double x, y, shape[np][2], xc[np], vel, scale, age, agemax, maxhunger;//more variables.
  Polygon p;//fish shape.
  Rectangle hungerbar1, hungerbar2;//outer/inner hunger bars.
  Color fishcol;//fish colour
  void initFish(bool cont, short fishtype);//fish initialization
  void rm(bool showhunger,double&);//random motion
  void killFish();//remove fish
  void resurrectFish();//add fish
  void goaway(int, int);//quick run away algo
  int col[3];
};
void hungerReset(int size, fishy * f);//reset fish hungers.
