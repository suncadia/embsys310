  
// Bit banding homework enabling clock on LED1

#if 1
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))


volatile int counter=0;
//int counter=0;

#define ORD14 (1<<14)
#define ORD5 (1<<5)

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[0] to 1
    
    // 1. Enable clock to Peripheral with bit banding
    // RCC_AHB2ENR |= 0x1;
    *((unsigned int*)((0x42000000) + (0x2104C*32)+(0*4))) = 0x1;
    
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to [0:1]  // To enable PA5 as output
     GPIOA_MODER &= 0xFFFFF7FF;

    // GPIOA Base Address: 0x4800000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 // Turn LED ON
    // Set bit[5] to 0 // Turn LED OFF

    while(1)
    {
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA_ODR |= ORD5;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        GPIOA_ODR &= ~ORD5;
    }
}
#endif