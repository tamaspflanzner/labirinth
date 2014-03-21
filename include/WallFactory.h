#ifndef WALLFACTORY_H
#define WALLFACTORY_H


class WallFactory
{
    public:

        Wall[/* 8*körökSzáma*/] walls;

        WallFactory();
        WallFactory(int);
        generateWalls(int);
        virtual ~WallFactory();
    protected:
    private:
};

#endif // WALLFACTORY_H
