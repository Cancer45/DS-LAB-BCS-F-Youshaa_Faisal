#include <iostream>

class IntNode
{
    public:
    int value;
    IntNode* next = nullptr;

    IntNode() {}
    IntNode(int value, IntNode* next) : value(value), next(next) {}
};

void pushNode(IntNode*& head, IntNode*& tail, int new_value)
{
    IntNode* new_node = new IntNode;

    new_node->value = new_value;

    if (tail != nullptr)
    {
        tail->next = new_node;
        tail = tail->next;
        new_node->next = nullptr;
    }

    else
    {
        tail = new_node;
    }

    if (head == nullptr)
    {
        head = new_node;
    }
}

void deleteList(IntNode* head)
{
    IntNode* tmp = head;
    while(tmp != nullptr)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }
}

void singleToDouble(IntNode* head, IntNode* tail)
{
    
} 

int main ()
{

}