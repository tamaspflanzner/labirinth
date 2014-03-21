#ifndef WALL_H
#define WALL_H

#include "Constants.h"
#include "Point.h"

class Wall
{
    public:
        Point origo; //k�z�ppont, de csak fel�lr�l (teh�t az als� t�glatest k�z�ppontja)
        int length;
        bool orientation;

        Point[4] points;

        Rectangle[6] rectangles;

        Wall();
        Wall(bool, int, Point);
        void createWall(boolean, int, Point);
        void createRectangles();

        virtual ~Wall();



    protected:
    private:
};

#endif // WALL_H
