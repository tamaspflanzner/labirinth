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
    if(orientation){ //mer�leges
        points[0] =* (new Point(origo->x - length/2, 0, origo->z+Constants::SPACE/2)); //bal k�zeli
        points[1] =* (new Point(origo->x + length/2, 0, origo->z+Constants::SPACE/2)); //jobb k�zeli
        points[2] =* (new Point(origo->x + length/2, 0, origo->z-Constants::SPACE/2)); //jobb t�voli
        points[3] =* (new Point(origo->x - length/2, 0, origo->z-Constants::SPACE/2)); //bal t�voli
    }else{ //p�rhuzamos
        points[0] =* (new Point(origo->x - Constants::SPACE/2, 0, origo->z+length/2)); //bal k�zeli
        points[1] =* (new Point(origo->x + Constants::SPACE/2, 0, origo->z+length/2)); //jobb k�zeli
        points[2] =* (new Point(origo->x + Constants::SPACE/2, 0, origo->z-length/2)); //jobb t�voli
        points[3] =* (new Point(origo->x - Constants::SPACE/2, 0, origo->z-length/2)); //bal t�voli
    }

    createRectangles();
}

void Wall::createRectangles(){
    rectangles = new Rectangle[6];

    //mer�leges oldalak
    rectangles[0] =* (new Rectangle(&points[0] /*bal k�zel*/,&points[1] /*jobb k�zel*/)); //el�ls�
    rectangles[1] =* (new Rectangle(&points[3] /*bal t�vol*/,&points[2] /*jobb t�vol*/)); //h�ts�

    //p�rhuzamos oldalak
    rectangles[2] =* (new Rectangle(&points[0] /*bal k�zel*/,&points[3] /*bal t�vol*/)); //bal oldal
    rectangles[3] =* (new Rectangle(&points[1] /*jobb k�zel*/,&points[2] /*jobb t�vol*/)); //jobb oldal

    //teteje �s alja !nem kellenek az �tk�z�shez, csak a text�r�hoz!
    rectangles[4] =* (new Rectangle(true /*fent*/, &points[0] /*bal k�zel*/,&points[1] /*jobb k�zel*/, length)); //teteje
    rectangles[5] =* (new Rectangle(false /*lent*/, &points[0] /*bal k�zel*/,&points[1] /*jobb k�zel*/, length)); //alja

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
