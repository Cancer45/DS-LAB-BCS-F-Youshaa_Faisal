#include <iostream>
#define QUEUESIZE 10

//Circular Queue Implementation
class IntQueue
{
    //rear and front are set to where they will add or remove their next values respectively
    int queue[QUEUESIZE];
    int rear = 0;
    int front = 0;
    
    public:
    IntQueue() {}
    
    bool enqueue(int value)
    {
        int tmp = (rear + 1) % QUEUESIZE;
        if (tmp != front)
        {
            queue[rear] = value;
            rear = tmp;
            return true;
        }
        
        return false;
    }
    
    int dequeue()
    {
        if (front == 0 && rear == 0)
        {
            std::cout << "UNDERFLOW\n";
            return -1;
        }
        
        int tmp = queue[front];
        front = (front + 1) % QUEUESIZE;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        
        return tmp;
    }
    
    void displayAll()
    {
        for (int i = front; i < rear; i = (i + 1) % QUEUESIZE)
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
    
    my_queue.displayAll();
}