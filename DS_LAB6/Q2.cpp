#include <iostream>
#define STACKSIZE 10

class IntNode
{
    public:
    int value;
    IntNode* next = nullptr;
};

class IntStack
{
    IntNode* top = nullptr;
    int curr_size = 0;
    
    public:
    IntStack() {}
    
    bool push(int value)
    {
        if (curr_size < STACKSIZE)
        {
            IntNode* new_node = new IntNode;
            new_node->value = value;
            
            if (!top)
            {
                top = new_node;
            }
            
            else
            {
                new_node->next = top;
                top = new_node;    
            }
            
            curr_size++;
            return true;
        }
        
        std::cout << "STACK OVERFLOW\n";
        return false;
    }
    
    int pop()
    {
        if (curr_size > 0)
        {
            int tmp_val;
            IntNode* tmp = top;
            tmp_val = tmp->value;
            
            top = top->next;
            delete tmp;
            
            curr_size--;
            return tmp_val;
        }
        
        std::cout << "STACK UNDERFLOW";
        return -1;
    }
    
    int peek()
    {
        if (curr_size > 0)
        return top->value;
        
        return -1;
    }
    
    void printStack()
    {
        IntNode* curr = top;
        while(curr)
        {
            std::cout << curr->value << std::endl;
            curr = curr->next;
        }
    }
};

int main() {
    class IntStack this_stack;
    
    this_stack.push(34);
    this_stack.push(11);
    this_stack.push(59);
    
    std::cout << this_stack.peek() << std::endl;
    this_stack.pop();
    this_stack.pop();
    this_stack.printStack();
    return 0;
}