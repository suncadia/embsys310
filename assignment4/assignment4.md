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


2. Create a function “func1” with 5 arguments and call “func1” from within another function
“func2”. Trace thru the assembler and note:
a. How does the calling function “func2” pass the values to the called function “func1”?

It stores the location of the stack pointer, then moves the arguments onto the stack.

b. What extra code did the compiler generate before calling the function “func1” with the
multiple arguments?

The caller is responsible for pushing the R2-R4 and LR registers to the stack.

   0x800'0050: 0xb51c         PUSH      {R2-R4, LR}
   0x800'0052: 0x0004         MOVS      R4, R0
  


c. What extra code did the compiler generate inside the called function “funct1” with the
multiple list of arguments?

Storing the input arguments to the stack.

   0x800'0054: 0x9400         STR       R4, [SP]
   0x800'0056: 0x0023         MOVS      R3, R4
   0x800'0058: 0x0022         MOVS      R2, R4
   0x800'005a: 0x0021         MOVS      R1, R4
   0x800'005c: 0x0020         MOVS      R0, R4




