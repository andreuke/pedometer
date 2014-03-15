/* 
 * File:   stats.cpp
 * Author: user
 * 
 * Created on March 15, 2014, 6:10 PM
 */

#include "stats.h"


int height;
float distance, calories, speed;
int old_steps = 0;

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

void Stats::setHeight(int h) {
    height = h;
}

float Stats::getDistance() {
    return distance;
}    

float Stats::getCalories() {
    return calories;
}    

float Stats::getSpeed() {
    return speed;
}  

void Stats::start() {
    int steps = Pedometer::get_instance()->getSteps() - old_steps;
    float stride = computeStride(steps);
    
    distance += stride * steps;
    speed = stride * steps / 2;
    
    calories += computeCalories(speed);

    
    usleep(2000000);
}
