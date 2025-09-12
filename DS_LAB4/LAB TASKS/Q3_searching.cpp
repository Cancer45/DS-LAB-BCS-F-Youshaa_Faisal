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

bool ascendingSortCheck(int* to_check, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (to_check[i] > to_check[i + 1])
        return false;
    }
    
    return true;
}

void interpolationSearch(int* sorted_array, int lower, int upper, int target_value)
{

    if (target_value < sorted_array[lower])
    {
        std::cout << "no such value" << std::endl;
        return;
    }
    
    if (lower > upper)
    {
        std::cout << "invalid range" << std::endl;
        return;
    }
    

    if (upper == lower)
    {
        if (sorted_array[upper] == target_value)
        std::cout << "found at: " << upper << std::endl;

        else
        std::cout << "no such value" << std::endl;
        return;
    }

    int pos = lower + (((upper - lower) / (sorted_array[upper] - sorted_array[lower])) * (target_value - sorted_array[lower]));

    if (sorted_array[pos] > target_value)
    interpolationSearch(sorted_array, lower, pos - 1, target_value);

    else if (sorted_array[pos] < target_value)
    interpolationSearch(sorted_array, pos + 1, upper, target_value);

    else
    {
        std::cout << "found at: " << pos << std::endl;
        return;
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
    int *dataset, size, target_value;

    std::cout << "size: ";
    std::cin >> size;
    
    dataset = new int[size];

    for (int i = 0; i < size; i++)
    {
        std::cout << "value no. " << i + 1 << ": ";
        std::cin >> dataset[i];
    }
    
    std::cout << "target value: ";
    std::cin >> target_value;

    if (!ascendingSortCheck(dataset, size))
    {
        bubbleSort(dataset, size);
        
        std::cout << "SORTED\n";
        printArray(dataset, size);
    }
    

    interpolationSearch(dataset, 0, size - 1, target_value);

    delete [] dataset;
}