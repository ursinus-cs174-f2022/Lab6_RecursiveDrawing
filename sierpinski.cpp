#include "simplecanvas/simplecanvas.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/**
 * @brief Draw a triangle
 * 
 * @param canvas Reference to canvas on which to draw the triangle
 * @param ax X coordinate of first point
 * @param ay Y coordinate of first point
 * @param bx X coordinate of second point
 * @param by Y coordinate of second point
 * @param cx X coordinate of third point
 * @param cy Y coordinate of third point
 * @param R Red channel
 * @param G Green channel
 * @param B Blue channel
 */
void drawTriangle(SimpleCanvas& canvas, int ax, int ay, 
                    int bx, int by, int cx, int cy,
                    uint8_t R, uint8_t G, uint8_t B) {
    canvas.drawLine(ax, ay, bx, by, R, G, B);
    canvas.drawLine(ax, ay, cx, cy, R, G, B);
    canvas.drawLine(bx, by, cx, cy, R, G, B);
}

void draw(SimpleCanvas& canvas, int res) {
    canvas.clearRect(255, 255, 255);
    int ax = 10;
    int ay = res-10;
    int bx = res-10;
    int by = res-10;
    int cx = (ax+bx)/2;
    int cy = 10;
    drawTriangle(canvas, ax, ay, bx, by, cx, cy, 255, 0, 0);
    // TODO: Fill this in and make it recursive
}

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: ./sierpinski <resolution> <filenameOut>\n";
        return 1;
    }
    int res = atoi(argv[1]);
    SimpleCanvas canvas(res, res);
    draw(canvas, res);
    canvas.write(string(argv[2]));
    return 0;
}