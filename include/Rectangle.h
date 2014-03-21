#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
    public:
        Point points[4];

        Rectangle();
        Rectangle(Point, Point);
        Rectangle(bool, Point, Point);
        createRectangle(Point, Point);
        createSpecialRectangle(Point, Point); //tetõ és alja
        virtual ~Rectangle();
    protected:
    private:
};

#endif // RECTANGLE_H
