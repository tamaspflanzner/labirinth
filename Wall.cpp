#include "Wall.h"

Wall::Wall()
{
    //ctor
}

Wall::Wall(bool orientation, int length, Point *origo){
    createWall(orientation, length, origo);
}

void Wall::createWall(bool orientation, int length, Point *origo){

    this->orientation = orientation;
    this->length = length;
    this->origo = origo;

    points = new Point[4];
    if(orientation){ //merõleges
        points[0] =* (new Point(origo->x - length/2, 0, origo->z+Constants::SPACE/2)); //bal közeli
        points[1] =* (new Point(origo->x + length/2, 0, origo->z+Constants::SPACE/2)); //jobb közeli
        points[2] =* (new Point(origo->x + length/2, 0, origo->z-Constants::SPACE/2)); //jobb távoli
        points[3] =* (new Point(origo->x - length/2, 0, origo->z-Constants::SPACE/2)); //bal távoli
    }else{ //párhuzamos
        points[0] =* (new Point(origo->x - Constants::SPACE/2, 0, origo->z+length/2)); //bal közeli
        points[1] =* (new Point(origo->x + Constants::SPACE/2, 0, origo->z+length/2)); //jobb közeli
        points[2] =* (new Point(origo->x + Constants::SPACE/2, 0, origo->z-length/2)); //jobb távoli
        points[3] =* (new Point(origo->x - Constants::SPACE/2, 0, origo->z-length/2)); //bal távoli
    }

    createRectangles();
}

void Wall::createRectangles(){
    rectangles = new Rectangle[6];

    //merõleges oldalak
    rectangles[0] =* (new Rectangle(&points[0] /*bal közel*/,&points[1] /*jobb közel*/)); //elülsõ
    rectangles[1] =* (new Rectangle(&points[3] /*bal távol*/,&points[2] /*jobb távol*/)); //hátsó

    //párhuzamos oldalak
    rectangles[2] =* (new Rectangle(&points[0] /*bal közel*/,&points[3] /*bal távol*/)); //bal oldal
    rectangles[3] =* (new Rectangle(&points[1] /*jobb közel*/,&points[2] /*jobb távol*/)); //jobb oldal

    //teteje és alja !nem kellenek az ütközéshez, csak a textúrához!
    rectangles[4] =* (new Rectangle(true /*fent*/, &points[0] /*bal közel*/,&points[1] /*jobb közel*/, length)); //teteje
    rectangles[5] =* (new Rectangle(false /*lent*/, &points[0] /*bal közel*/,&points[1] /*jobb közel*/, length)); //alja

}


Wall::~Wall()
{
    //dtor
}
/*
std::ostream& operator<<(std::ostream& os, const Wall& w)
{
  os << "W[" << w.orientation <<"; "<<w.length <<"; "<<*w.origo <<"]";

    for(int i=0; i<6; i++){
        os << std::endl << i << ": " << w.rectangles[i];
    }

  return os;
}
*/
