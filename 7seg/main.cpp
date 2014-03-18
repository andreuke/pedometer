#include <stdlib.h>
#include <cstdio>
#include "util/software_i2c.h"


using namespace std;
using namespace miosix;

#define SLAVE_ADDRESS 0x48 // the slave address (example)

typedef Gpio<GPIOB_BASE,6>  scl;
typedef Gpio<GPIOB_BASE,9>  sda;
typedef SoftwareI2C<sda,scl> i2c;

int number;
uint8_t *sendByte = (uint8_t*)&number;

int main()
{
    
    for(;;) {
        i2c::init();
    
        i2c::sendStart();
        for(int i = 0; i < sizeof(number); i++) {
            i2c::send(sendByte[i]);
        }
        i2c::sendStop();
        delayMs(1000);
    }
}


