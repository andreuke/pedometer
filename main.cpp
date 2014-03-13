#include <stdlib.h>
#include <cstdio>
#include <pthread.h>
#include "miosix.h"
#include "accelerometer.h"
#include "pedometer.h"

using namespace std;
using namespace miosix;

Pedometer pedometer;

int main() {
   pedometer.start();
   
   for(;;) {
       int prova = pedometer.getSteps();
       printf("STEPS = %d \n\n\n", prova);
       usleep(1000000);
   }
   return 0;
}