#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"
#include "Constants.h"

class Rectangle
{
    public:
        Point* points;

        Rectangle();
        Rectangle(Point*, Point*);
        Rectangle(bool, Point*, Point*, int);
        void createRectangle(Point*, Point*);
        void createSpecialRectangle(bool, Point*, Point*, int); //tetõ és alja
        virtual ~Rectangle();
        //friend std::ostream& operator<<(std::ostream&, const Rectangle& r);
    protected:
    private:
};

#endif // RECTANGLE_H
