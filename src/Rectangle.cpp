#include "Rectangle.h"

Rectangle::Rectangle(Point *p1, Point *p2){
    createRectangle(p1,p2);
}

Rectangle::Rectangle(bool up, Point *p1, Point *p2){
    createSpecialRectangle(up,p1,p2);
}

void Rectangle::createRectangle(Point *p1 /*bal lent*/, Point *p2/*jobb lent*/){
    points = new Point[4];

    points[0] = *p1; //bal lent
    points[1] = *p2; //jobb lent

    points[2] = *p2; //jobb fent
    points[2].y = Constants::HEIGHT;

    points[3] = *p1; //bal lent
    points[3].y = Constants::HEIGHT;

}

void Rectangle::createSpecialRectangle(bool up, Point *p1 /*bal közel*/, Point *p2/*jobb közel*/){ //tetõ és alja
    points = new Point[4];

    points[0] = *p1; //bal közel
    points[1] = *p2; //jobb közel

    points[2] = *p2; //jobb távol
    points[2].z += Constants::SPACE;

    points[3] = *p1; //bal távol
    points[2].z += Constants::SPACE;

    if(up){
        for(int i=0; i<4; i++){
            points[i].y = Constants::HEIGHT;
        }
    }

}

Rectangle::Rectangle()
{
    //ctor
}

Rectangle::~Rectangle()
{
    //dtor
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
  os << "R[ " << r.points[0] <<"; "<<r.points[1] <<"; "<<r.points[2] <<"; "<<r.points[3] <<" ]";
  return os;
}
