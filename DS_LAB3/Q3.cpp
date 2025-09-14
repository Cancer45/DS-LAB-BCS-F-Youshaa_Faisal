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

void printList(IntNode* head)
{
    IntNode* curr = head;

    while(curr != nullptr)
    {
        std::cout << curr->value << std::endl;
        curr = curr->next;
    }
}

void reverseList(IntNode*& head, IntNode*& tail, unsigned int k)
{
    IntNode *curr, *next, *prev, *tmp_head;

    //to complete
}

int main ()
{
    IntNode *head = nullptr, *tail = nullptr;
    int value, size, k;
    
    std::cout << "size: ";
    std::cin >> size;

    std::cout << "k: ";
    std::cin >> k;

    for (int i = 0; i < size; i++)
    {
        std::cout << "Node " << i + 1 << " Value: ";
        std::cin >> value;

        pushNode(head, tail, value);
    }

    reverseList(head, tail, k);
    printList(head);

    deleteList(head);
}