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

int main ()
{
    int array[5] = {3, 77, 110, 9, 27};
    
    std::cout << "UNSORTED\n";
    printArray(array, 5);
    
    bubbleSort(array, 5);
    
    std::cout << "UNSORTED\n";
    printArray(array, 5);
}