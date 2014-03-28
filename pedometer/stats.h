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
    
    /**
    * Singleton
    */
    static Stats& get_instance();
    
    /**
    * \brief Sets the height of the user
    * \param h, the height of an user
    * \return Nothing
    */
    void setHeight(float height);
    
    /**
    * \brief Return the covered distance
    * \return dist
    */
    float getDistance();
    
    /**
    * \brief Return the number of burned calories.
    * \return calories
    */
    float getCalories();
    
    /**
    * \brief Return the instantaneous speed.
    * \return speed
    */
    float getSpeed();
    
    /**
    * \brief Computes the number of steps executed every 2s and updates the value of dist, speed and calories
    * \return Nothing
    */
    void start();

private:
    Stats();

};

#endif	/* STATS_H */

