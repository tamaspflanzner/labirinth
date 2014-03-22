#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
    public:
        Point();
        Point(int,int,int);
        virtual ~Point();

        int x;
        int y;
        int z;

        friend std::ostream& operator<<(std::ostream&, const Point&);

    protected:
    private:
};

#endif // POINT_H
