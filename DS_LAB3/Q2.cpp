#include <iostream>

class IntNode
{
    public:
    int value;
    IntNode* next = nullptr;

    IntNode() {}
    IntNode(int value, IntNode* next) : value(value), next(next) {}
};

class LinkedList
{
    public:
    IntNode *head = nullptr, *tail = nullptr;
    int size = 0;

    LinkedList() {}
    LinkedList(IntNode* head, IntNode* tail, int size) : head(head), tail(tail), size(size) {}
   ~LinkedList()
    {
        IntNode* tmp = head;

        while(tmp != nullptr)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
    }

    void pushNode(IntNode* new_node)
    {
       if (head == nullptr)
       {
            head = new_node;
            tail = new_node;
            size++;
            return;
       }

        tail->next = new_node;
        tail = tail->next;
        tail->next = nullptr;

        size++;
    }

    void printList()
    {
        IntNode* curr = head;

        while(curr != nullptr)
        {
            std::cout << curr->value << std::endl;
            curr = curr->next;
        }
    }
};

IntNode* returnLesserNode(IntNode*& node1, IntNode*& node2)
{

    if (node1 == nullptr || node2 == nullptr)
    return nullptr;

    IntNode* to_return;
    if (node1->value > node2->value)
    {
        to_return = node2;
        node2 = node2->next;
        return to_return;
    }

    to_return = node1;
    node1 = node1->next;
    return to_return;
}

LinkedList mergeSortedList(const LinkedList& list1, const LinkedList& list2)
{
    IntNode *curr1 = list1.head, *curr2 = list2.head;
    IntNode *new_curr, *lesser;
    LinkedList new_list;

    while(1)
    {
        if (curr2 == nullptr)
        {
            while(curr1 != nullptr)
            {
                IntNode* new_node = new IntNode;
                new_node->value = curr1->value;

                new_list.pushNode(new_node);
                curr1 = curr1->next;
            }

            break;
        }

        if (curr1 == nullptr)
        {
            while(curr2 != nullptr)
            {
                IntNode* new_node = new IntNode;
                new_node->value = curr2->value;

                new_list.pushNode(new_node);
                curr2 = curr2->next;
            }

            break;
        }

        IntNode* new_node = new IntNode;
        lesser = returnLesserNode(curr1, curr2);
        new_node->value = lesser->value;
        
        new_list.pushNode(new_node);
    }
    
    return new_list;
}

int main ()
{
    unsigned int size[2];
    int value;
    
    LinkedList list[2];
    std::cout << "LIST 1\nsize: ";
    std::cin >> size[0];
    
    std::cout << "LIST 2\nsize: ";
    std::cin >> size[1];

    for (int j = 0; j < 2; j++)
    {
        std::cout << "LIST " << j + 1 << std::endl;
        for (int i = 0; i < size[j]; i++)
        {
            IntNode* new_node = new IntNode;

            std::cout << "Node " << i + 1 << " Value: ";
            std::cin >> value;

            new_node->value = value;

            list[j].pushNode(new_node);
        }
    }

    mergeSortedList(list[0], list[1]).printList();
}