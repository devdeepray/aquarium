#include <simplecpp>
struct food {
  food();//constructor
  Circle C[100];//food particles
  int fposition[100][2];//position of particles
  int f;
  void foodreset();//triggers foodmove.
  void foodmove();//movdes food and keeps hiding them randomly.
};
