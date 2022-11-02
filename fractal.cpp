#include "simplecanvas/simplecanvas.h"
#include "shape.h"

/**
 * A recursive helper method for drawing the Sierpinski triangle
 * 
 * @param canvas Reference to canvas on which to draw
 * @param tri Reference to current triangle we're processing
 * @param depth Depth of recursion
 * @param maxDepth Maximum depth of recursion
 */
void drawSierpinskiRec(SimpleCanvas* canvas, SierpinskiTriangle* tri, int depth, int maxDepth) {
    // Cast this to a triangle to use the ordinary draw method
    if (maxDepth == 0) {
        ((Triangle*)tri)->draw(canvas);
    }
    else {
        // TODO: Fill this in.  Make recursive calls to draw
        // three smaller triangles
        Point d = tri->ab.getMidpoint();
        Point f = tri->ac.getMidpoint();
        Point e = tri->bc.getMidpoint();
        SierpinskiTriangle tri1(tri->thickness, tri->color, tri->a, d, f, maxDepth-1);
        tri1.draw(canvas);
        SierpinskiTriangle tri2(tri->thickness, tri->color, d, tri->b, e, maxDepth-1);
        tri2.draw(canvas);
        SierpinskiTriangle tri3(tri->thickness, tri->color, f, e, tri->c, maxDepth-1);
        tri3.draw(canvas);
    }
}


void SierpinskiTriangle::draw(SimpleCanvas* canvas) {
    drawSierpinskiRec(canvas, this, 0, maxDepth);
}



/**
 * A recursive helper method for drawing the Koch curve
 * 
 * @param canvas Reference to canvas on which to draw
 * @param ab Current line segment we're processing
 * @param depth depth of recursion
 * @param maxDepth Maximum depth of recursion
 */
void drawKochRec(SimpleCanvas* canvas, KochCurve* ab, int depth, int maxDepth) {
    // Cast this to an ordinary line segment to use the LineSegment draw method
    ((LineSegment*)ab)->draw(canvas);
    
    // TODO: Fill this in.  Make recursive calls to draw
    // three smaller line segments
}


void KochCurve::draw(SimpleCanvas* canvas) {
    canvas->clearRect(255, 255, 255);
    drawKochRec(canvas, this, 0, maxDepth);
}
