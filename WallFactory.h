#ifndef WALLFACTORY_H
#define WALLFACTORY_H

#include "Wall.h"
#include "Constants.h"

class WallFactory
{
    public:
        int nrOfRounds;
        Wall* walls;

        WallFactory();
        WallFactory(int);
        void generateWalls(int);
        virtual ~WallFactory();
        //friend std::ostream& operator<<(std::ostream& os, const WallFactory& wf);
    protected:
    private:
};

#endif // WALLFACTORY_H
