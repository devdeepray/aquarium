#include <simplecpp>
#include "grass.h"
grass::grass(int y) {//constructor that sets y value of grass , color etc.
  for(int j = 0; j < 120; j++) {
      layerVertices[2*j][0] = 20 * j / 3;
      peakXPos[j] = 20 * j / 3;
      layerVertices[2*j][1] = -50 - randuv(0, 20);
      layerVertices[2*j+1][0] = 20 * j / 3 + 2;
      layerVertices[2*j+1][1] = -2;
    }
  layerVertices[240][0] = 0;
  layerVertices[240][1] = 0;
  grassLayer.reset(0, 600.0 - y, layerVertices, 241);
  grassLayer.setColor(COLOR(0, 255 - 8 * yPos, 0));
  grassLayer.setFill(true);
  i = 30 * (randuv(0, 10));//asynchronous swaying of diffrent instances.
  yPos = y;
}
void grass::swayStep(double &darkfac) {//sways the grass one step.
  for(int j = 0; j < 240; j += 2)//move vertices.
    layerVertices[j][0] = peakXPos[j/2] + 10 * sine(i);
    grassLayer.show();
  grassLayer.reset(0, 600.0 - yPos, layerVertices, 241);
  grassLayer.setColor(COLOR(0, (230 - 3 * yPos)*darkfac, 0));
  grassLayer.setFill(true);
  grassLayer.imprint();
  grassLayer.hide();
  i += 5;
  i %= 360;
}
