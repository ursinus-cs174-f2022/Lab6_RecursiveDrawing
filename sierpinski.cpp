#include <iostream>
#include <string>
#include <stdio.h>
#include "simplecanvas/simplecanvas.h"
#include "shape.h"
using namespace std;


int main(int argc, char** argv) {
    if (argc < 4) {
        cout << "Usage: ./sierpinski <resolution> <max depth> <filenameOut>\n";
        return 1;
    }
    int res = atoi(argv[1]);
    int maxDepth = atoi(argv[2]);

    SimpleCanvas canvas(res, res);
    canvas.clearRect(255, 255, 255);
    float thickness = 1;
    int color[3] = {255, 0, 0};
    Point a(thickness, color, 10, res-10);
    Point b(thickness, color, res-10, res-10);
    Point c(thickness, color, res/2, 10);
    SierpinskiTriangle tri(thickness, color, a, b, c, maxDepth);
    tri.draw(&canvas);
    canvas.write(string(argv[3]));

    return 0;
}