#include "RandomNumberGenerator.h"
#include <stdlib.h>

int RandomNumberGenerator::generateNumberBetween(int min, int max)
{
   max = (max - min) + 1;
   return (rand() % max) + min;
}
