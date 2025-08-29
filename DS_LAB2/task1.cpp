#include <iostream>
#include <cstdio>

class DynamicArray
{
    int* array = nullptr;
    unsigned int size;
    
    public:
    DynamicArray (unsigned int size) : size(size)
    {
        this->array = new int[size];
        
        for (int i = 0; i < size; i++)
        array[i] = 0;
    }
    
    ~DynamicArray ()
    {
        delete [] array;
    }
    
    void updateValue (unsigned int index, int new_value)
    {
        if (index + 1 > size)
        {
            std::cout << "SIZE: " << size << "\n Input index less than size\n Try again\n";
            return;
        }
        
        array[index] = new_value;
        std::cout << "Value Updated\n";
    }
    
    void printAll ()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << std::endl;
        }
    }
};

int main ()
{
    int array_size;
    
    do
    {
        std::cout << "size of array: ";
        std::cin >> array_size;
    }while(array_size < 0);
    
    DynamicArray array(array_size);
    
    int index, value;
    std::string ans;
    while(1)
    {
        std::cout << "Edit Array? ('y' if yes)" << std::endl;
        std::cin >> ans;
        if (ans[0] == 'y')
        {
            do
            {
                std::cout << "Index: ";
                std::cin >> index; 
            }while(index < 1);
            
            std::cout << "New Value: ";
            std::cin >> value;
            
            array.updateValue(index - 1, value);
        }
        
        else
        {
            array.printAll();
            return 0;
        }
    }
}