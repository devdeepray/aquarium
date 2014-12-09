#include <simplecpp>
struct grass {
  Polygon grassLayer;
  double layerVertices[241][2];
  int i;//for asynchronous swaying.
  int yPos;
  double peakXPos[120];//peak positions.
  grass(int y);
  void swayStep(double&);
};
