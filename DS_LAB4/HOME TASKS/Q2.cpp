#include <iostream>

void bubbleSort(int* unsorted_array, int size)
{
    int tmp;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (unsorted_array[j] > unsorted_array[j + 1])
            {
                tmp = unsorted_array[j];
                unsorted_array[j] = unsorted_array[j + 1];
                unsorted_array[j + 1] = tmp;
            }
        }
    }
}

void printArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i];
        if (i != size - 1)
        std::cout << ", ";
    }
    
    std::cout << std::endl;
}

int inputIntArray(int*& int_array)
{
    int size;
    std::cout << "size of array: ";
    std::cin >> size;
    int_array = new int[size];

    for (int i = 0; i < size; i++)
    {
        std::cout << "value " << i + 1 << ": ";
        std::cin >> int_array[i];
    }

    return size;
}

int main ()
{
    int* int_array;
    int size = inputIntArray(int_array);
    
    std::cout << "UNSORTED\n";
    printArray(int_array, size);
    
    bubbleSort(int_array, size);
    
    std::cout << "UNSORTED\n";
    printArray(int_array, size);
}