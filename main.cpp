#include <iostream>


#include "WallFactory.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    WallFactory *wallF = new WallFactory(1);

    cout << *wallF << endl;

    /*
    Point *p = new Point(0,0,0);
    Wall *wall = new Wall(true, 25, p);
    cout << *wall << endl;
    */

    return 0;
}
