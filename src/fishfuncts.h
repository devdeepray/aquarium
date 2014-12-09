#include <simplecpp>
#include "fishy.h"
#include <fstream>
#include "food.h"
#include "textbox.h"
int searchEmpty ( fishy*, const int& );//searche for dead fish to replace.
void addFish ( fishy*, const int&, const int& );//adds new fish.
void drawfish ( int, int, int, float );//draws a fish for buttons.
void drawfishes();//draws all fishes using drawfish.
void aquareset ( fishy*, const int&, textbox & );//resets aquarium
void quit ( fishy * f, const int & n, const int & time );//quits.
void fromfile ( fishy * f , int&, int& );//takes all data from file.
void givefood ( fishy * f, food & fishfood, int & numFishes, bool * hungry );//triggers food.
bool checkHungry ( fishy * f, int & numFishes ) ;//checks if fishes are hungry.
bool checkDeath ( int & numFishes, fishy * f, bool & hungry );//checks if fishes are dead.
