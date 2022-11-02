#ifndef SHAPE_H
#define SHAPE_H

#include "simplecanvas/simplecanvas.h"

class Shape {
    protected:
        float thickness;
        int color[3];
    
    public:
        /**
         * Constructor for a shape
         * @param thickness Thickness of pen drawing
         * @param color RGB Color to draw
         */
        Shape(float thickness, int color[3]);
        
        // Dummy constructor for empty object declarations
        Shape(){};
        
        /**
         * Setter method for a color
         * @param color An RGB color to set
         */
        void setColor(int color[3]);
        
        /**
         * Setter method for thickness
         * @param thickness The thickness
         */
        void setThickness(float thickness);
        /**
         * Subclasses should override this method to actually draw things
         */
        void draw(SimpleCanvas* canvas);
};




class Point: public Shape {
    private:
        float ax;
        float ay;
    
    public:
        /**
         * Constructor for a point
         * @param thickness Radius of the point when drawing
         * @param color Color to draw
         * @param ax X coordinate of the point
         * @param ay Y coordinate of the point
         */
        Point(float thickness, int color[3], float ax, float ay);

        // Dummy constructor for empty object declarations
        Point(){};

        void setX(float ax);
        void setY(float ay);
        float getX();
        float getY();
        void draw(SimpleCanvas* canvas);
};






class LineSegment: public Shape {
    friend class KochCurve;
    private:
        Point a;
        Point b;
    
    public:
        /**
         * Line segment constructor that accepts point objects
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param a The first point
         * @param b The second point
         */
        LineSegment(float thickness, int color[3], Point a, Point b);

        // Dummy constructor for empty object declarations
        LineSegment(){};
        
        /**
         * Update the first point
         * @param a Set the point a
         */
        void setA(Point a);
        
        
        /**
         * Update the second point
         * @param b Set the point b
         */
        void setB(Point b);

        /**
         * Return the first point on the line segment
         * @return Point The first point
         */
        Point getA();

        /**
         * Return the first point on the line segment
         * @return Point The first point
         */
        Point getB();

        /**
         * Get the midpoint between the two endpoints
         * 
         * @return Point The midpoint
         */
        Point getMidpoint();

        
        /**
         * Get the length of this line segment by using the 
         * Pythagorean theorem
         * @return The length of the line segment
         */
        float getLength();
        

        /**
         * Draw the line segment to a particular canvas
         * @param canvas Pointer to canvas
         */
        void draw(SimpleCanvas* canvas);
};



class Triangle: public Shape {
    // This makes it so we can access a, b, c, ab, ac, and bc from within
    // the SierpinskiTriangle class
    friend class SierpinskiTriangle;
    protected:
        Point a, b, c;
        LineSegment ab, ac, bc;

    public:
        /**
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param a The first point
         * @param b The second point
         * @param c The third point
         */
        Triangle(float thickness, int color[3], Point a, Point b, Point c);
        
        void draw(SimpleCanvas* canvas);
};



class SierpinskiTriangle: public Triangle {
    private:
        int maxDepth; // Maximum depth of recursion

    public:
        /**
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param a The first point
         * @param b The second point
         * @param c The third point
         * @param maxDepth Maximum depth of the recursion
         */
        SierpinskiTriangle(float thickness, int color[3], Point a, Point b, Point c, int maxDepth):Triangle(thickness, color, a, b, c) {
            this->maxDepth = maxDepth;
        };

        void draw(SimpleCanvas* canvas);
};


class KochCurve: public LineSegment {
    private:
        int maxDepth; // Maximum depth of recursion
    
    public:
        /**
         * Line segment constructor that accepts point objects
         * @param thickness Thickness of pen drawing
         * @param color Color to draw
         * @param a The first point
         * @param b The second point
         */
        KochCurve(float thickness, int color[3], Point a, Point b, int maxDepth):LineSegment(thickness, color, a, b) {
            this->maxDepth = maxDepth;
        };

        void draw(SimpleCanvas* canvas);
};

#endif