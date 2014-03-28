/* 
 * File:   lis302dl.h
 * Author: Andrea Piscitello, Giada Tacconelli
 * 
 * Created on March 15, 2014, 6:10 PM
 */
#ifndef LIS302DL_H
#define LIS302DL_H

/**
 * \brief Lis302dl header file
 */
class Lis302dl
{
public:
	Lis302dl();
        
        /**
        * \brief Return the value read on the X axis
        * \return X, the value read on the X axis.
        */
	int8_t getX();
           
        /**
        * \brief Return the value read on the Y axis
        * \return Y, the value read on the Y axis.
        */
	int8_t getY();  
            
        /**
        * \brief Return the value read on the Z axis
        * \return Z, the value read on the Z axis.
        */
	int8_t getZ();
};

#endif //LIS302DL_H







