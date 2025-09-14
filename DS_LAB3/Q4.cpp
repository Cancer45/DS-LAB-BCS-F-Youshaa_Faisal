#include <iostream>

class IntNode
{
    public:
    int value;
    IntNode* next = nullptr;

    IntNode() {}
    IntNode(int value, IntNode* next) : value(value), next(next) {}
};

void pushNodeCircular(IntNode*& head, IntNode*& tail, int new_value)
{
    IntNode* new_node = new IntNode;

    new_node->value = new_value;

    if (tail != nullptr)
    {
        tail->next = new_node;
        tail = tail->next;
        new_node->next = head;
    }

    else
    {
        tail = new_node;
        tail->next = head;
    }

    if (head == nullptr)
    {
        head = new_node;
        head->next = tail;
    }
}

void deleteNode(IntNode* prev, IntNode* to_delete)
{
    if (to_delete == nullptr || prev == nullptr) return;

    prev->next = to_delete->next;
    delete to_delete;
}

IntNode* Josephus (IntNode* head, IntNode* tail, int k)
{
    IntNode *prev = tail, *curr = head;

    while(1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == prev)
        {
            curr->next = nullptr;
            return curr;
        }

        deleteNode(prev, curr);
        curr = prev->next;
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

int main ()
{
    IntNode* position;
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

        pushNodeCircular(head, tail, value);
    }

    position = Josephus(head, tail, k);
    std::cout << "position: " << position->value << std::endl;
    deleteList(position);
}