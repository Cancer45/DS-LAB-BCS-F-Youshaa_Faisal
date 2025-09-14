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
    IntNode* head = nullptr;
    int size = 0;

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

    void pushNode(IntNode& new_node)
    {
       new_node.next = head;
       head = &new_node;

       size++;
    }

    bool isPalindrome()
    {
        int* tmp_array = new int[size];

        IntNode* tmp = head;
        int i = 0;

        while(tmp != nullptr)
        {
            tmp_array[i] = tmp->value;
            tmp = tmp->next;
            i++;
        }

        for (int i = 0; i < size / 2; i++)
        {
            if (tmp_array[i] != tmp_array[size - 1 - i])
            return false;
        }

        return true;
    }
};

int main ()
{
    LinkedList list;
    int list_size, tmp_value;

    std::cout << "list size: ";
    std::cin >> list_size;

    for (int i = 0; i < list_size; i++)
    {
        IntNode* new_node = new IntNode;

        std::cout << "Node " << i + 1 << " Value: ";
        std::cin >> tmp_value;

        new_node->value = tmp_value;

        list.pushNode(*new_node);
    }

    if (list.isPalindrome())
    std::cout << "list is palindrome" << std::endl;

    else
    std::cout << "list is not palindrome" << std::endl;
}