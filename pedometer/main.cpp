#include <stdlib.h>
#include <cstdio>
#include <pthread.h>
#include "miosix.h"
#include "pedometer.h"
#include "stats.h"

using namespace std;
using namespace miosix;

Pedometer* pedometer;


void *startPedometer(void *arg) {
    //miosix::Thread::getCurrentThread()->setPriority(1);
    pedometer->start();
}

void *startStats(void *arg) {
    Stats::get_instance().setHeight(1.80);
    Stats::get_instance().start();
}

void *stepMonitor(void *arg) {
     //miosix::Thread::getCurrentThread()->setPriority(0);
     for(;;) {
       int steps = pedometer->getSteps();
       Stats stats = Stats::get_instance();
       printf("STEPS = %d \n", steps);
       //printf("CALORIES = %f \n", stats.getCalories());
       //printf("DISTANCE = %f \n", stats.getDistance());
       //printf("SPEED = %f \n", stats.getSpeed());
       usleep(1000000);
   }
}


int main() {
    
   
    pedometer = pedometer->get_instance();
   
    pthread_t pedometerThread;
    pthread_create(&pedometerThread,NULL,&startPedometer, NULL);
    
    pthread_t statsThread;
    pthread_create(&statsThread, NULL, &startStats, NULL);
    
    pthread_t stepThread;
    pthread_create(&stepThread, NULL, &stepMonitor, NULL);
    
   pthread_join(pedometerThread,NULL);
   pthread_join(stepThread,NULL);
   pthread_join(statsThread, NULL);

    
   return 0;
}