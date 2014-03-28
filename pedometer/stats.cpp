/* 
 * File:   stats.cpp
 * Author: Andrea Piscitello, Giada Tacconelli
 * 
 * Created on March 15, 2014, 6:10 PM
 */
#include <stdlib.h>
#include <cstdio>
#include "miosix.h"
#include "stats.h"
#include "pedometer.h"

using namespace std;
using namespace miosix;

float height;
float dist, calories, speed;
int old_steps = 0;


/**
* \brief Computes the stride depending on the number of steps carried out (in the last 2 seconds) and the user’s height
* \param steps
* \return height*k which represents the strides
*/
float computeStride(int steps) {
    
    switch(steps) {
        case(1):
            return height/5;
        case(2):
            return height/4;
        case(3):
            return height/3;
        case(4):
            return height/2;
        case(5):
            return height/1.2;     
        case(6):
        case(7):
            return height;
        default:
            return height*1.2;
        }
}

/**
* \brief Computes the number of calories
* \param speed
* \return cal, the number of calories burned in the last 2 seconds.
*/
int computeCalories(int speed) {
    if(speed < 1)
        return 0;
    else {
        if(speed < 8)
            return 10;
        else if(speed < 12) {
            return 15;
        }
        else if(speed < 16) {
            return 20;
        }
        else if(speed < 20) {
            return 25;
        }
    }
}


Stats::Stats() {
    
}


Stats& Stats::get_instance() {
    static Stats instance;
    return instance;
}


void Stats::setHeight(float h) {
    height = h;
}


float Stats::getDistance() {
    return dist;
}    


float Stats::getCalories() {
    return calories;
}    


float Stats::getSpeed() {
    return speed;
}  

void Stats::start() {
    for(;;) {
        int new_steps = Pedometer::get_instance()->getSteps();
        int steps =  new_steps - old_steps;
        float stride = computeStride(steps);

        dist += stride * steps;
        speed = stride * steps * 3600/ 2000;

        calories += computeCalories(speed);
        
        old_steps = new_steps;

        usleep(2000000);
    }
}
