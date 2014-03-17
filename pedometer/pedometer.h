#ifndef PEDOMETER_H
#define PEDOMETER_H

class Pedometer
{
    
private:
     Pedometer();
        
        static Pedometer* pPedometer;
    
public:
   
    
    static Pedometer* get_instance();
    
        void start();
        
        int getSteps();
        
};

#endif //PEDOMETER_H



