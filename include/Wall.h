#ifndef WALL_H
#define WALL_H

#include "Constants.h"
#include "Rectangle.h"
#include "Point.h"

class Wall
{
    public:
        Point *origo; //középpont, de csak felülrõl (tehát az alsó téglatest középpontja)
        int length;
        bool orientation;

        Point *points;

        Rectangle *rectangles;

        Wall();
        Wall(bool, int, Point*);
        void createWall(bool, int, Point*);
        void createRectangles();

        virtual ~Wall();

        friend std::ostream& operator<<(std::ostream& os, const Wall& w);

    protected:
    private:
};

#endif // WALL_H
