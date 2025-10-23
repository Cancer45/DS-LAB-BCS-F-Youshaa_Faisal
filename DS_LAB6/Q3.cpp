#include <iostream>
#define QUEUESIZE 10

class IntQueue
{
    int queue[QUEUESIZE];
    int rear = 0;
    
    public:
    IntQueue() {}
    
    bool isEmpty()
    {
        if (rear == 0)
        return true;
        
        return false;
    }
    
    bool isFull()
    {
        if (rear == QUEUESIZE)
        return true;
        
        return false;
    }
    
    bool enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "OVERFLOW\n";
            return false;
        }
        
        queue[rear++] = value;
        return true;
    }
    
    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "UNDERFLOW\n";
            return -1;
        }
        
        int tmp = queue[0];
        rear--;
        
        for (int i = 0; i < rear; i++)
        queue[i] = queue[i + 1];
        
        return tmp;
    }
    
    void displayAll()
    {
        for (int i = 0; i < rear; i++)
        {
            std::cout << queue[i];
            if (i != rear - 1)
            std::cout << ", ";
        }
        
        std::cout << std::endl;
    }
};

int main()
{
    IntQueue my_queue;
    my_queue.enqueue(4);
    my_queue.enqueue(7);
    my_queue.enqueue(10);
    my_queue.dequeue();
    
    my_queue.displayAll();    
}