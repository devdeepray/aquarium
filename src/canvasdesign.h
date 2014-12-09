#include <simplecpp>
void button(double cx, double cy, double width, double height, string text);
void paintScr(double&);
void drawArtifacts();
void pebbles(int x, int y, double&);
struct watersurface{
    double points[ 21 ][ 2 ];
    Polygon p;
    Rectangle r;
    double heightvar[ 19 ];
    double phase[ 19 ];
    watersurface();
    void morph(double&);
};

