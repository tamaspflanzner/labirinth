#include "Rectangle.h"

Rectangle::Rectangle(Point *p1, Point *p2){
    createRectangle(p1,p2);
}

Rectangle::Rectangle(bool up, Point *p1, Point *p2, int length){
    createSpecialRectangle(up,p1,p2, length);
}

void Rectangle::createRectangle(Point *p1 /*bal lent*/, Point *p2/*jobb lent*/){
    points = new Point[4];

	
	    points[0] = *p1; //bal lent
	    points[1] = *p2; //jobb lent

	    points[2] = *(new Point(p2->x, p2->y, p2->z)); //jobb fent
	    points[2].y = Constants::HEIGHT;

	    points[3] = *(new Point(p1->x, p1->y, p1->z)); //bal fent
	    points[3].y = Constants::HEIGHT;

}

void Rectangle::createSpecialRectangle(bool up, Point *p1 /*bal közel*/, Point *p2/*jobb közel*/, int length){ //tetõ és alja
    points = new Point[4];
if(p2->x - p1->x == Constants::SPACE ){ //párhuzamos
	points[0] = *(new Point(p1->x, p1->y, p1->z)); //bal közel
    points[1] = *(new Point(p2->x, p2->y, p2->z)); //jobb közel

    points[2] = *(new Point(p2->x, p2->y, p2->z)); //jobb távol
    points[2].z -= length;

    points[3] = *(new Point(p1->x, p1->y, p1->z)); //bal távol
    points[3].z -= length;
}else{ //merőleges
	points[0] = *(new Point(p1->x, p1->y, p1->z)); //bal közel
    points[1] = *(new Point(p2->x, p2->y, p2->z)); //jobb közel

    points[2] = *(new Point(p2->x, p2->y, p2->z)); //jobb távol
    points[2].z -= Constants::SPACE;

    points[3] = *(new Point(p1->x, p1->y, p1->z)); //bal távol
    points[3].z -= Constants::SPACE;
}
    

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
/*
std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
  os << "R[ " << r.points[0] <<"; "<<r.points[1] <<"; "<<r.points[2] <<"; "<<r.points[3] <<" ]";
  return os;
}
*/
