#include "stack.h"


// Globals
static int stack[STACK_SIZE];
static int top = 0;



// FIFO Queue is Empty if putPtr==getPtr;
// FIFO Queue is Full if putPtr+1 > Address of last element in the queue;

// Initialize internals of the stack
void stack_init(void)
{
    top = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        stack[i] = '\0';
    }
}

// check if stack is full 
unsigned int isFull(void)
{
       
    if(top > STACK_SIZE)
        return ERROR; //error checking
    
    else if(top == STACK_SIZE)
        return 1;   // full
    
    else
        return 0;   // not full
}

// check if stack is empty
unsigned int isEmpty(void)
{
           
    if(top > STACK_SIZE)
        return ERROR; //error checking
 
    else if(top == 0)
        return 1;
    
    else 
        return 0;
        
}


// push data to the stack
// If queue is full return error
// Otherwise return success
int push(int data)
{
    if (isFull())
    {
        // stack is full
        return ERROR;
    }
    
    stack[top] = data;
    top++;
    
    return SUCCESS;
    
}


// push data to the stack
// If queue is full return error
// Otherwise return success
int pop(int* data)
{
    if (isEmpty())
    {
        // stack is empty
        return ERROR;
    }
    top--;
    *data = stack[top];
  
    
    return SUCCESS;
    
}

