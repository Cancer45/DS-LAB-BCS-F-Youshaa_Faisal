#include <iostream>
#define STACKSIZE 10

class IntStack
{
    int array[STACKSIZE];
    int top = -1;
    
    public:
    IntStack() {}
    
    bool push(int value)
    {
        if (top < STACKSIZE - 1)
        {
            array[++top] = value;
            return true;
        }
        
        std::cout << "STACK OVERFLOW\n";
        return false;
    }
    
    int pop()
    {
        if (top >= 0)
        {
            return array[top--];
        }
        
        std::cout << "STACK UNDERFLOW";
        return -1;
    }
    
    int peek()
    {
        if (top >= 0)
        return array[top];
        
        return -1;
    }
    
    void printStack()
    {
        for (int i = top; i >= 0; i--)
        std::cout << array[i] << std::endl;
    }
};

int main() {
    class IntStack this_stack;
    
    this_stack.push(34);
    this_stack.push(11);
    this_stack.push(59);
    
    std::cout << this_stack.peek() << std::endl;
    this_stack.pop();
    this_stack.printStack();
    return 0;
}