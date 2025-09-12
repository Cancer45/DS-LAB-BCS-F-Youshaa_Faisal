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

int main ()
{
    int array[5] = {3, 9, 27, 77, 110};

    linearSearch(array, 5, 27);
}