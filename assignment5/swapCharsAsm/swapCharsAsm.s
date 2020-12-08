/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for dividing by 2
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Swaps two char inputs

Parameters      : R0 & R1 char pointers.
Return value    : R0
*******************************************************************************/  
  
swapCharsAsm
    LDRB R2, [R0]    // Load R0 into R2
    LDRB R3, [R1]    // Load R1 into R3
    STRB R3, [R0]    // R3 = R0
    STRB R2, [R1]    // R2 = R1
    BX LR           // return (with function result in R0)

    END
