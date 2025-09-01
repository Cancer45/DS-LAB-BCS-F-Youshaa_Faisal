#include <iostream>

class IntPointer
{
    int* pointer = nullptr;

    IntPointer() {}
    IntPointer(int* ptr) : pointer(ptr) {}
    
    ~IntPointer()
    {
        delete pointer;
    }

    void setValue(int value)
    {
        *pointer = value;
    }

    int getValue()
    {
        if (pointer == nullptr)
        return 0;

        return *pointer;
    }

    void setPtrValue(int* ptr_value)
    {
        pointer = ptr_value;
    }

    int* getPtrValue()
    {
        return pointer;
    }

    void release()
    {
        delete pointer;
        pointer = nullptr;
    }
};