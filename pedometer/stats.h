/* 
 * File:   stats.h
 * Author: user
 *
 * Created on March 15, 2014, 6:10 PM
 */

#ifndef STATS_H
#define	STATS_H

class Stats {
    
public:
    static Stats& get_instance();
    void setHeight(float height);
    float getDistance();
    float getCalories();
    float getSpeed();
    void start();

private:
    Stats();

};

#endif	/* STATS_H */

