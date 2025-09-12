#include <iostream>

void descendingBubbleSort(int* unsorted_array, int size)
{
    int tmp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (unsorted_array[j] < unsorted_array[j + 1])
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
    int array[10] = {5, 1, 3, 6, 2, 9, 7, 4, 8, 10};
    
    std::cout << "UNSORTED\n";
    printArray(array, 10);
    
    descendingBubbleSort(array, 10);
    
    std::cout << "UNSORTED\n";
    printArray(array, 10);
}