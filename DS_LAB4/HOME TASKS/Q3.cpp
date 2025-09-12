#include <iostream>

void insertionSort(int* unsorted_array, int size)
{
    int tmp, min, min_index;

    for (int i = 0; i < size; i++)
    {
        
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

std::string intToTitle(int num)
{
    if (num == 0)
    return "CEO";

    if (num == 1)
    return "CEO";

    if (num == 2)
    return "CEO";

    if (num == 3)
    return "CEO";

    if (num == 4)
    return "CEO";

    if (num == 5)
    return "CEO";

    if (num == 6)
    return "CEO";

    if (num == 7)
    return "CEO";
}

int main ()
{
    int array[5] = {3, 77, 110, 9, 27};
    
    std::cout << "UNSORTED\n";
    printArray(array, 5);
    
    selectionSort(array, 5);
    
    std::cout << "UNSORTED\n";
    printArray(array, 5);
}