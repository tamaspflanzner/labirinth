#include "WallFactory.h"

WallFactory::WallFactory(int nrOfRounds){
    generateWalls(nrOfRounds);
}

WallFactory::generateWalls(int nrOfRounds){
    walls[] = new Wall[ 8*nrOfRounds ];

    for(int roundNr = 1; roundNr <= nrOfRounds; roundNr++){
        int size = Constants.SPACE/2 + roundNr*Constants.SPACE*2;
        //merõleges

            //bal közel | ln = left near
            Point lnOrigo = new Point(-(size/2)-Constants.SPACE/2, 0, roundNr*Constants.SPACE*2+Constants.SPACE/2);
            Wall lnWall = new Wall(true, size, lnOrigo);
            walls[ (roundNr-1)*8 ] = lnWall;

            //jobb közel | rn = right near
            Point rnOrigo = new Point((size/2)+Constants.SPACE/2, 0, roundNr*Constants.SPACE*2+Constants.SPACE/2);
            Wall rnWall = new Wall(true, size, rnOrigo);
            walls[ (roundNr-1)*8 +1 ] = rnWall;

            //jobb távoli | rn = right far
            Point rfOrigo = new Point((size/2)+Constants.SPACE/2, 0, -(roundNr*Constants.SPACE*2+Constants.SPACE/2));
            Wall rfWall = new Wall(true, size, rfOrigo);
            walls[ (roundNr-1)*8 +2 ] = rfWall;

            //bal távoli | lf = left far
            Point lfOrigo = new Point(-(size/2)-Constants.SPACE/2, 0, -(roundNr*Constants.SPACE*2+Constants.SPACE/2);
            Wall lfWall = new Wall(true, size, lfOrigo);
            walls[ (roundNr-1)*8 +3] = lfWall;

        //párhuzamos
            //bal közel | ln = left near
            Point lnOrigo = new Point(-(roundNr*Constants.SPACE*2+Constants.SPACE/2), 0, -(size/2)-Constants.SPACE/2);
            Wall lnWall = new Wall(false, size, lnOrigo);
            walls[ (roundNr-1)*8 +4 ] = lnWall;

            //jobb közel | rn = right near
            Point rnOrigo = new Point(roundNr*Constants.SPACE*2+Constants.SPACE/2 , 0, -(size/2)-Constants.SPACE/2);
            Wall rnWall = new Wall(false, size, rnOrigo);
            walls[ (roundNr-1)*8 +5 ] = rnWall;

            //jobb távoli | rn = right far
            Point rfOrigo = new Point(roundNr*Constants.SPACE*2+Constants.SPACE/2, 0, (size/2)+Constants.SPACE/2);
            Wall rfWall = new Wall(false, size, rfOrigo);
            walls[ (roundNr-1)*8 +6 ] = rfWall;

            //bal távoli | lf = left far
            Point lfOrigo = new Point(-(roundNr*Constants.SPACE*2+Constants.SPACE/2) , 0, (size/2)+Constants.SPACE/2);
            Wall lfWall = new Wall(false, size, lfOrigo);
            walls[ (roundNr-1)*8 +7] = lfWall;
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
