Answers to questions:

1a. What instructions does the compiler produce in assembly for “writing” to the GPIO bit
when using bit-band address?

        GPIOA_ODR |= ORD5;
   0x800'006c: 0x4a0c         LDR.N     R2, [PC, #0x30]         ; 0x4800'0014
   0x800'006e: 0x6813         LDR       R3, [R2]
   0x800'0070: 0xf053 0x0320  ORRS.W    R3, R3, #32             ; 0x20
   0x800'0074: 0x6013         STR       R3, [R2]

1b. What were the instructions produced when writing to the GPIOx_ODR without using bitbanding?
        GPIOA_ODR |= ORD5;
   0x800'006c: 0x4a0c         LDR.N     R2, [PC, #0x30]         ; 0x4800'0014
   0x800'006e: 0x6813         LDR       R3, [R2]
   0x800'0070: 0xf053 0x0320  ORRS.W    R3, R3, #32             ; 0x20
   0x800'0074: 0x6013         STR       R3, [R2]
   
Instructions are the same because we can only use bit banding on the clock.  The Gpio output data register is outside of the addressable bit banding region.

