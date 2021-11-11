#include <iostream>
#include "funcs.h"
using namespace std; 

int main()
{
  Coord3D shape = {10,20,30};
  Coord3D shape1 = {-20,21,-22};
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};
  cout << length(&shape) << endl;
  cout << fartherFromOrigin(&shape, &shape1) << endl;
  move(&pos, &vel, 2.0);
  cout << pos.x << " " << pos.y << " " << pos.z << endl;
  Coord3D *ppos = createCoord3D(10,20,30);
  Coord3D *pvel = createCoord3D(5.5,-1.4,7.77);
  move(ppos, pvel, 10.0);
  cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;
  deleteCoord3D(ppos);
  deleteCoord3D(pvel);
  return 0;
}
