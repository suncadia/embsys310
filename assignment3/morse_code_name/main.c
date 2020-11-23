// Morse Code "John"

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

#define DOT 1
#define DASH 3
#define SPACE_MORSE 1
#define SPACE_LETTERS 3
#define SPACE_WORDS 6 // 7 = 6 + SPACE_LETTERS

#define MIN_COUNTER 100000

void led(int duration, char led_on)
{
        int counter=0;
        
        if(!led_on)
        {
            while (counter < MIN_COUNTER * duration)
            {
            counter++;
            }

            GPIOA_ODR |= ORD5;
        } 
        else
        {
    
            while (counter < MIN_COUNTER * duration)
            {
            counter++;
            }

            GPIOA_ODR &= ~ORD5;
        }
        
}

// Function to convert letter to led morse code blinks
void morse_letter(char letter)
{
    
    switch(letter)
    {            
    case 'o':   // - - -
            led(DASH,1);
            led(SPACE_MORSE,0);
            
            led(DASH,1);
            led(SPACE_MORSE,0);            
            
            led(DASH,1);      
           
            break;
        
    case 'h':   // * * * *
            led(DOT,1);
            led(SPACE_MORSE,0);
            
            led(DOT,1);
            led(SPACE_MORSE,0);            
            
            led(DOT,1);
            led(SPACE_MORSE,0);
            
            led(DOT,1);
                           
            break;
        
    case 'j':   // * - - -
            led(DOT,1);
            led(SPACE_MORSE,0);
            
            led(DASH,1);
            led(SPACE_MORSE,0);            
            
            led(DASH,1);
            led(SPACE_MORSE,0);
            
            led(DASH,1);
      
            break;
            
         
    case 'n':   // * - *

            led(DASH,1);
            led(SPACE_MORSE,0);            
            
            led(DOT,1);
      
            break;
    default:
        break;
       
    }
    
    led(SPACE_LETTERS,0);
}


void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    RCC_AHB2ENR |= 0x1;

    
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable PA5 as output
    GPIOA_MODER &= 0xFFFFF7FF;

    morse_letter('j');
    morse_letter('o');
    morse_letter('h');
    morse_letter('n');
    led(SPACE_WORDS,0);       

 
}
#endif
