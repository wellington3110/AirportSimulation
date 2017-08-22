#include <cstdlib>

int main() {
   int max= 16;
   int min= 4;
   max = (max - min) + 1;
   for (int prox= 0; prox < 1000;)
      prox= (rand() % max) + min;
   return 0;
}