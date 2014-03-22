#include "Point.h"

Point::Point()
{
    //ctor
}

Point::Point(int px, int py, int pz){
    x = px;
    y = py;
    z = pz;
}

Point::~Point()
{
    //dtor
}
/*
std::ostream& operator<<(std::ostream& os, const Point& p)
{
  os << "P[" << p.x <<";"<<p.y<<";"<<p.z<<"]";
  return os;
}
*/
