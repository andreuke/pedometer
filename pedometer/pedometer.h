/* 
 * File:   pedometer.h
 * Author: Andrea Piscitello, Giada Tacconelli
 * 
 * Created on March 15, 2014, 6:10 PM
 */
#ifndef PEDOMETER_H
#define PEDOMETER_H

class Pedometer
{
    
private:
    /**
     * Private constructor
     */
     Pedometer();
        
        static Pedometer* pPedometer;
    
public:
   
   /**
    * Singleton factor method
    */
    static Pedometer* get_instance();
        
        /**
        * \brief Start the pedometer module.
        * \return Nothing
        */
        void start();
        
        /**
        * \return steps, the number of steps
        */
        int getSteps();
        
};

#endif //PEDOMETER_H



