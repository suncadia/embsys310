#include <assert.h>
#include "stack.h"

int main()
{
    int result1;
    int result2;
    int testData;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 60;
    testData = 55;
    stack_init();
    
    // Act:
    result1 = pop(&testData);
      
    // Assert:
    assert(-1 == result1);

    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testData = 55;
    stack_init();
    
    // Act:
    result1 = push(1);
    result2 = pop(&testData);
    
    // Assert:
    assert(SUCCESS == result1);
    assert(SUCCESS == result2);
    assert(1 == testData);
    

    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testData = 55;
    stack_init();
    
    // Act:
    push(1);
    push(3);
    push(5);                                    
    
    // Assert:
    assert(SUCCESS == pop(&testData));
    assert(5 == testData);

    assert(SUCCESS == pop(&testData));
    assert(3 == testData);

    assert(SUCCESS == pop(&testData));
    assert(1 == testData);

   
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testData = 55;
    stack_init();
    
    // Act:
    for(int i=0; i<STACK_SIZE; i++)
    {
        assert(SUCCESS == push(i));
    }
                                  
    
    // Assert:
    assert(ERROR == push(6));
    

    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testData = 55;
    stack_init();
    
    // Act:
    push(1);
    push(3);
    push(5);                                    
    
    // Assert:
    assert(SUCCESS == pop(&testData));
    assert(5 == testData);

    assert(SUCCESS == push(5));

    assert(SUCCESS == pop(&testData));
    assert(5 == testData);
    
    assert(SUCCESS == pop(&testData));
    assert(3 == testData);

    assert(SUCCESS == pop(&testData));
    assert(1 == testData);
    

    // ***********************************************************************
    // Test6: Fill stack and retrieve all items. Do it twice in a row.
    // ***********************************************************************
    // Arrange:
    testData = 55;
    stack_init();
    
    // Act:
    push(1);
    push(3);
    push(5);                                    
    
    // Assert:
    assert(SUCCESS == pop(&testData));
    assert(5 == testData);

    assert(SUCCESS == pop(&testData));
    assert(3 == testData);

    assert(SUCCESS == pop(&testData));
    assert(1 == testData);
    
    assert(SUCCESS == push(1));
    assert(SUCCESS == push(3));
    assert(SUCCESS == push(5));
    
    assert(SUCCESS == pop(&testData));
    assert(5 == testData);

    assert(SUCCESS == pop(&testData));
    assert(3 == testData);

    assert(SUCCESS == pop(&testData));
    assert(1 == testData);
        
    return 0;
}
