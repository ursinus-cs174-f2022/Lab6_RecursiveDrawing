#include "simplecanvas/simplecanvas.h"
#include "shape.h"

/**
 * A recursive helper method for drawing the Sierpinski triangle
 * 
 * @param canvas Reference to canvas on which to draw
 * @param tri Current triangle we're processing
 * @param depth depth of recursion
 */
void SierpinskiTriangle::drawRec(SimpleCanvas* canvas, SierpinskiTriangle& tri, int depth) {
    // Cast this to a triangle to use the ordinary draw method
    ((Triangle)tri).draw(canvas);

    // TODO: Fill this in.  Make recursive calls to draw
    // three smaller triangles
}


void SierpinskiTriangle::draw(SimpleCanvas* canvas) {
    canvas->clearRect(255, 255, 255);
    drawRec(canvas, *this, 0);
}



/**
 * A recursive helper method for drawing the Koch curve
 * 
 * @param canvas Reference to canvas on which to draw
 * @param ab Current line segment we're processing
 * @param depth depth of recursion
 */
void KochCurve::drawRec(SimpleCanvas* canvas, KochCurve& ab, int depth) {
    // Cast this to an ordinary line segment to use the LineSegment draw method
    ((LineSegment)ab).draw(canvas);
    
    // TODO: Fill this in.  Make recursive calls to draw
    // three smaller line segments
}


void KochCurve::draw(SimpleCanvas* canvas) {
    canvas->clearRect(255, 255, 255);
    drawRec(canvas, *this, 0);
}
