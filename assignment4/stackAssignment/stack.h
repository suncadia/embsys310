/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 3
#define SUCCESS 0
#define ERROR -1

void stack_init(void);
int push(int data);
int pop(int* data);
unsigned int isEmpty(void);
unsigned int isFull(void);

#endif
