#include <stdlib.h>
#include <cstdio>
#include <pthread.h>
#include "miosix.h"
#include "pedometer.h"


using namespace std;
using namespace miosix;

Pedometer* pedometer;

void *startPedometer(void *arg) {
    //miosix::Thread::getCurrentThread()->setPriority(1);
    pedometer->start();
}

void *stepMonitor(void *arg) {
     //miosix::Thread::getCurrentThread()->setPriority(0);
     for(;;) {
       int steps = pedometer->getSteps();
       printf("STEPS = %d \n", steps);
       usleep(1000000);
   }
}


int main() {
    
   
    pedometer = pedometer->get_instance();
   
    pthread_t pedometerThread;
    pthread_create(&pedometerThread,NULL,&startPedometer, NULL);
    
    pthread_t stepThread;
    pthread_create(&stepThread, NULL, &stepMonitor, NULL);
    
   pthread_join(pedometerThread,NULL);
   pthread_join(stepThread,NULL);

    
   return 0;
}