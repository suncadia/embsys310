#include <stdint.h>
#include "delay.h"
//#include "stm32f401xe.h"    // CMSIS - Device Specific File
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"

// Blinks Led 1 & Led2 for homework assignment6 problem#1.

#define LED_ON 1
#define LED_OFF 0
#define DELAY_DURATION 100000
volatile int counter=0;


void control_user_led1(uint8_t state, uint32_t duration);

void main(void)
{     

    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral  
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // Enable Gpio B
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; // Enable Gpio A
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOB->MODER &= ~GPIO_MODER_MODE14_1;
    GPIOB->MODER |= GPIO_MODER_MODE14_0;
    
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF
    
    // GPIOA Base Address: 0x4800000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 // Turn LED ON
    // Set bit[5] to 0 // Turn LED OFF 
    
    
    while(1)
    {
        control_user_led1(LED_ON, DELAY_DURATION);
        control_user_led1(LED_OFF, DELAY_DURATION);  
    }    

}
