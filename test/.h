#include "Airport.h"
#include "Plane.h"

int main()
{
   TowerOfCommand* a= Airport::getInstance();
   Aircraft* b= new Plane(a, 20);
  return 0;
}
