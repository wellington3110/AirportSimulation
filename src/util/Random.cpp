#include "Random.h"
#include <stdlib.h>

int Random::generateNumberBetween(int min, int max)
{
   max = (max - min) + 1;
   return (rand() % max) + min;
}
