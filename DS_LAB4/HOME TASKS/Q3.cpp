#include <iostream>

void selectionSort(int* unsorted_array, int size)
{
    int swap_index, tmp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (unsorted_array[j] < unsorted_array[i])
            swap_index = j;
        }
        tmp = unsorted_array[i];
        unsorted_array[i] = unsorted_array[swap_index];
        unsorted_array[swap_index] = tmp;
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
    
    selectionSort(int_array, size);
    
    std::cout << "UNSORTED\n";
    printArray(int_array, size);
}