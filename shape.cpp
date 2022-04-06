#include "simplecanvas/simplecanvas.h"
#include "shape.h"
#include <math.h>
#include <iostream>

using namespace std;

Shape::Shape(float thickness, int color[3]) {
    this->thickness = thickness;
    for (int k = 0; k < 3; k++) {
        this->color[k] = color[k];
    }
}

/**
 * Setter method for a color
 * @param color An RGB color to set
 */
void Shape::setColor(int color[3]) {
    for (int k = 0; k < 3; k++) {
        this->color[k] = color[k];
    }
}

/**
 * Setter method for thickness
 * @param thickness The thickness
 */
void Shape::setThickness(float thickness) {
    this->thickness = thickness;
}

/**
 * Subclasses should override this method to actually draw things
 */
void Shape::draw(SimpleCanvas* canvas) {
    cout << "Warning: Calling draw on base class";
}

/////////////////////////////////////////////////////////

/**
 * Constructor for a point
 * @param thickness Radius of the point when drawing
 * @param color Color to draw
 * @param ax X coordinate of the point
 * @param ay Y coordinate of the point
 */
Point::Point(float thickness, int color[3], float ax, float ay):Shape(thickness, color) {
    this->ax = ax;
    this->ay = ay;
}

void Point::setX(float ax) {
    this->ax = ax;
}

void Point::setY(float ay) {
    this->ay = ay;
}

float Point::getX() {
    return ax;
}

float Point::getY() {
    return ay;
}


void Point::draw(SimpleCanvas* canvas) {
    canvas->fillCircle((int)ax, (int)ay, thickness, color[0], color[1], color[2]);
}



//////////////////////////////////////////////////



/**
 * Line segment constructor that accepts point objects
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param a The first point
 * @param b The second point
 */
LineSegment::LineSegment(float thickness, int color[3], 
                        Point a, Point b):Shape(thickness, color) {
    this->a = a;
    this->b = b;
}

/**
 * Update the first point
 * @param a Set the point a
 */
void LineSegment::setA(Point a) {
    this->a = a;
}


/**
 * Update the first point
 * @param a Set the point a
 */
void LineSegment::setB(Point b) {
    this->b = b;
}



/**
 * Return the first point on the line segment
 * @return Point The first point
 */
Point LineSegment::getA() {
    return a;
}

/**
 * Return the first point on the line segment
 * @return Point The first point
 */
Point LineSegment::getB(){
    return b;
}

/**
 * Get the midpoint between the two endpoints
 * 
 * @return Point The midpoint
 */
Point LineSegment::getMidpoint() {
    float mx = (a.getX() + b.getX()) / 2;
    float my = (a.getY() + b.getY()) / 2;
    return Point(thickness, color, mx, my);
}

/**
 * Get the length of this line segment by using the 
 * Pythagorean theorem
 * @return The length of the line segment
 */
float LineSegment::getLength() {
    float diffx = a.getX() - b.getX();
    float diffy = a.getY() - b.getY();
    return sqrt(diffx*diffx + diffy*diffy);
}


/**
 * Draw the line segment to a particular canvas
 * @param canvas Pointer to canvas
 */
void LineSegment::draw(SimpleCanvas* canvas) {
    canvas->drawLine(a.getX(), a.getY(), b.getX(), b.getY(), thickness, color[0], color[1], color[2]);
}





//////////////////////////////////////////////////



/**
 * An alternative line segment constructor that accepts point objects
 * @param canvas Reference to the canvas on which this should be drawn
 * @param thickness Thickness of pen drawing
 * @param color Color to draw
 * @param a The first point
 * @param b The second point
 * @param c The third point
 */
Triangle::Triangle(float thickness, int color[3], 
                        Point a, Point b, Point c):Shape(thickness, color) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->ab = LineSegment(thickness, color, a, b);
    this->bc = LineSegment(thickness, color, b, c);
    this->ac = LineSegment(thickness, color, a, c);
}


/**
 * Draw the triangle to a particular canvas
 * @param canvas Pointer to canvas
 */
void Triangle::draw(SimpleCanvas* canvas) {
    this->ab.draw(canvas);
    this->bc.draw(canvas);
    this->ac.draw(canvas);
}
