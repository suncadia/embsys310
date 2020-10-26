
1. Value of counter:
    locals window and registers window show counter as 0x800000000
    APSR N (negative) flag is set to 1.  This is the negative flag indicating the result MSB is set.
    V (overflow) flag is set because we added two numbers with the signed bit turned off.

2. Value of counter is 0x00000000.  
    The Vflag is not set because we added one number with sign bit on and one with signed bit off.
    The N (negative) flag is not set because the result was non-negative.

3. Value of counter is 0x80000000.
    The N and V flag is set.  However in unsigned arithmetic these flags are ignored and are not used.

4.  Value of counter is 0x00000000.
    The value of N and V flag is not set.  Unsigned arithmetic these flags are ignored.

5.  a - The scope of the counter variable is global.
    b - It is not viewable in the locals view.
    c - Live watch shows the counter.
    d - Location shows it as address 0x20000000

6.  a - Value of counter is 4.
    b - Because p_int pointer points to the same address as counter.

7.  a - Address of counter is 0x20000000.
    b - Counter is stored in RAM
    c - Value of counter is 4.
