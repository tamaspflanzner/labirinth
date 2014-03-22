#include "WallFactory.h"

WallFactory::WallFactory(int nrOfRounds){
    generateWalls(nrOfRounds);
}

void WallFactory::generateWalls(int nrOfRounds){
    this->nrOfRounds=nrOfRounds;

    walls = new Wall[ 8*nrOfRounds ];

    for(int roundNr = 1; roundNr <= nrOfRounds; roundNr++){
        int size = Constants::SPACE/2 + roundNr*Constants::SPACE*2;
        //merõleges

            //bal közel | ln = left near
            Point *lnOrigo = new Point(-(size/2)-Constants::SPACE/2, 0, roundNr*Constants::SPACE*2+Constants::SPACE/2);
            Wall *lnWall = new Wall(true, size, lnOrigo);
            walls[ (roundNr-1)*8 ] = *lnWall;

            //jobb közel | rn = right near
            Point *rnOrigo = new Point((size/2)+Constants::SPACE/2, 0, roundNr*Constants::SPACE*2+Constants::SPACE/2);
            Wall *rnWall = new Wall(true, size, rnOrigo);
            walls[ (roundNr-1)*8 +1 ] = *rnWall;

            //jobb távoli | rn = right far
            Point *rfOrigo = new Point((size/2)+Constants::SPACE/2, 0, -(roundNr*Constants::SPACE*2+Constants::SPACE/2));
            Wall *rfWall = new Wall(true, size, rfOrigo);
            walls[ (roundNr-1)*8 +2 ] = *rfWall;

            //bal távoli | lf = left far
            Point *lfOrigo = new Point(-(size/2)-Constants::SPACE/2, 0, -(roundNr*Constants::SPACE*2+Constants::SPACE/2));
            Wall *lfWall = new Wall(true, size, lfOrigo);
            walls[ (roundNr-1)*8 +3] = *lfWall;

        //párhuzamos
            //bal közel | ln = left near
            Point *lnOrigo2 = new Point(-(roundNr*Constants::SPACE*2+Constants::SPACE/2), 0, -(size/2)-Constants::SPACE/2);
            Wall *lnWall2 = new Wall(false, size, lnOrigo2);
            walls[ (roundNr-1)*8 +4 ] = *lnWall2;

            //jobb közel | rn = right near
            Point *rnOrigo2 = new Point(roundNr*Constants::SPACE*2+Constants::SPACE/2 , 0, -(size/2)-Constants::SPACE/2);
            Wall *rnWall2 = new Wall(false, size, rnOrigo2);
            walls[ (roundNr-1)*8 +5 ] = *rnWall2;

            //jobb távoli | rn = right far
            Point *rfOrigo2 = new Point(roundNr*Constants::SPACE*2+Constants::SPACE/2, 0, (size/2)+Constants::SPACE/2);
            Wall *rfWall2 = new Wall(false, size, rfOrigo2);
            walls[ (roundNr-1)*8 +6 ] = *rfWall2;

            //bal távoli | lf = left far
            Point *lfOrigo2 = new Point(-(roundNr*Constants::SPACE*2+Constants::SPACE/2) , 0, (size/2)+Constants::SPACE/2);
            Wall *lfWall2 = new Wall(false, size, lfOrigo2);
            walls[ (roundNr-1)*8 +7] = *lfWall2;
    }
}

WallFactory::WallFactory()
{
    //ctor
}

WallFactory::~WallFactory()
{
    //dtor
}
/*
std::ostream& operator<<(std::ostream& os, const WallFactory& wf)
{
  os << "WF[" ;
  for(int i=0; i<8*wf.nrOfRounds;i++){
        os << std::endl << wf.walls[i] <<";";
  }
  os << "]";
  return os;
}
*/
