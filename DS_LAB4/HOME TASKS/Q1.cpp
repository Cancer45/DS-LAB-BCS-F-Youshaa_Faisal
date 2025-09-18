#include <iostream>

void linearSearch(int* sorted_array, int size, int target_val)
{
    for (int i = 0; i < size; i++)
    {
        if (sorted_array[i] == target_val)
        {
            std::cout << "found at index: " << i << std::endl;
            return;
        }
    }
    
    std::cout << "target value not found: " << std::endl;
}

int inputIntArray(int*& int_array)
{
    int size;
    std::cout << "size of array: ";
    std::cin >> size;
    int_array = new int[size];

    std::cout << "ARRAY MUST BE SORTED\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "value " << i + 1 << ": ";
        std::cin >> int_array[i];
    }

    return size;
}

int main ()
{
    int* int_array, target_val;
    int size = inputIntArray(int_array);

    std::cout << "target value: ";
    std::cin >> target_val;
    
    linearSearch(int_array, size, target_val);
}