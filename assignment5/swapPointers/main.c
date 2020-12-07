// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#include "delay.h"

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))


#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

//volatile int counter=0;
int counter=0;

#define ORD14   (1<<14)
#define ORD5    (1<<5)



// ************** Demo 02 - Proper Swap ************** //

void swap(int* x, int* y);

void swapPtr(int **xSwap, int **ySwap);

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swapPtr(int **xSwap, int **ySwap)
{
    int *temp = *xSwap;
    *xSwap = *ySwap;
    *ySwap = temp;
}

int main(void)
{
    int x = 20000;
    int y = 10000;
    int *xPtr = &x;
    int *yPtr = &y;
    
    
    swapPtr(&xPtr,&yPtr);
    
 
    return 0;
}



