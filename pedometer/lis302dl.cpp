#include <stdlib.h>
#include <cstdio>
#include "miosix.h"
#include "lis302dl.h"

using namespace std;
using namespace miosix;

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef Gpio<GPIOA_BASE,5>  SPI_sclk;
typedef Gpio<GPIOA_BASE,7>  SPI_miso;
typedef Gpio<GPIOA_BASE,6>  SPI_mosi;
typedef Gpio<GPIOE_BASE,3>  SPI_CS;

//typedef enum { false, true } bool;

volatile int8_t x, y, z;
volatile uint8_t dummy;


void spi_init() {
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOEEN;
            
            SPI1->CR1 =  SPI_CR1_MSTR | SPI_CR1_SSI | SPI_CR1_SSM;
            
            SPI_sclk::mode(Mode::ALTERNATE);
            SPI_sclk::alternateFunction(5);
            SPI_sclk::speed(Speed::_50MHz);
            
            SPI_miso::mode(Mode::ALTERNATE);
            SPI_miso::alternateFunction(5);
            SPI_miso::speed(Speed::_50MHz);
            
            SPI_mosi::mode(Mode::ALTERNATE);
            SPI_mosi::alternateFunction(5);
            SPI_mosi::speed(Speed::_50MHz);
            
            SPI_CS::mode(Mode::OUTPUT);
            SPI_CS::speed(Speed::_50MHz);
            SPI_CS::high();
            
            SPI1->CR1 |= SPI_CR1_SPE;    
           
            /*INIT LIS302*/
            SPI_CS::low();
            SPI1->DR = 0x20;
            while((SPI1->SR & SPI_SR_TXE) == 0);
            while((SPI1->SR & SPI_SR_RXNE) == 0);
            dummy = SPI1->DR;

            SPI1->DR = 0x47;
            while((SPI1->SR & SPI_SR_TXE) == 0);
            while((SPI1->SR & SPI_SR_RXNE) == 0);
            dummy = SPI1->DR;
            SPI_CS::high();
}

Lis302dl::Lis302dl() {
	spi_init();
}

int8_t Lis302dl::getX() {
            SPI_CS::low();
            SPI1->DR = 0x80 | 0x29;
            while((SPI1->SR & SPI_SR_TXE) == 0);
            while((SPI1->SR & SPI_SR_RXNE) == 0);
            dummy = SPI1->DR;

            SPI1->DR = 0x00;
            while((SPI1->SR & SPI_SR_TXE) == 0);
            while((SPI1->SR & SPI_SR_RXNE) == 0);
            x = SPI1->DR;
            SPI_CS::high();
            return x;
            }
            
int8_t Lis302dl::getY() {
            SPI_CS::low();
            SPI1->DR = 0x80 | 0x2B;
            while((SPI1->SR & SPI_SR_TXE) == 0);
            while((SPI1->SR & SPI_SR_RXNE) == 0);
            dummy = SPI1->DR;

            SPI1->DR = 0x00;
            while((SPI1->SR & SPI_SR_TXE) == 0);
            while((SPI1->SR & SPI_SR_RXNE) == 0);
            y = SPI1->DR;
            SPI_CS::high();  
            return y;  
            }    
            
int8_t Lis302dl::getZ() {            
            SPI_CS::low();
            SPI1->DR = 0x80 | 0x2D;
            while((SPI1->SR & SPI_SR_TXE) == 0);
            while((SPI1->SR & SPI_SR_RXNE) == 0);
            dummy = SPI1->DR;

            SPI1->DR = 0x00;
            while((SPI1->SR & SPI_SR_TXE) == 0);
            while((SPI1->SR & SPI_SR_RXNE) == 0);
            z = SPI1->DR;
            SPI_CS::high();
            return z;
            }