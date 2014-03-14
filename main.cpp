#include <stdlib.h>
#include <cstdio>
#include <pthread.h>
#include "miosix.h"
#include "accelerometer.h"
#include "pedometer.h"

using namespace std;
using namespace miosix;

Pedometer* pedometer;

void *startPedometer(void *arg) {
    pedometer->start();
}

int main() {
   pedometer = Pedometer::get_instance();
   
    pthread_t pedometerThread;
    pthread_create(&pedometerThread,NULL,&startPedometer,NULL);
   
   /*for(;;) {
       int steps = pedometer->getSteps();
       printf("\n\nSTEPS = %d \n\n\n", steps);
       usleep(1000000);
   }*/
    
   pthread_join(pedometerThread,NULL);
   return 0;
}