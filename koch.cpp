#include <iostream>
#include <string>
#include <stdio.h>
#include "simplecanvas/simplecanvas.h"
#include "shape.h"
using namespace std;


int main(int argc, char** argv) {
    if (argc < 4) {
        cout << "Usage: ./koch <resolution> <max depth> <filenameOut>\n";
        return 1;
    }
    int res = atoi(argv[1]);
    int maxDepth = atoi(argv[2]);

    SimpleCanvas canvas(res, res/4);
    canvas.clearRect(255, 255, 255);
    float thickness = 1;
    int color[3] = {255, 0, 0};
    Point a(thickness, color, 10, res/4-10);
    Point b(thickness, color, res-10, res/4-10);
    KochCurve koch(thickness, color, a, b, maxDepth);
    koch.draw(&canvas);
    canvas.write(string(argv[3]));

    return 0;
}