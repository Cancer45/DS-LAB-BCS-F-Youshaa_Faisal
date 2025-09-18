#include <iostream>

void interpolationSearch(int* sorted_array, int lower, int upper, int target_value)
{

    if (target_value < sorted_array[lower])
    {
        std::cout << "no such value" << std::endl;
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
    
    interpolationSearch(int_array, 0, size - 1, target_val);
}