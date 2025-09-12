#include <iostream>

void binarySearch(int* sorted_array, int lower, int upper, int target_value)
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

    int mid = lower + (upper - lower) / 2;

    if (sorted_array[mid] > target_value)
    binarySearch(sorted_array, lower, mid - 1, target_value);

    else if (sorted_array[mid] < target_value)
    binarySearch(sorted_array, mid + 1, upper, target_value);

    else
    {
        std::cout << "found at: " << mid << std::endl;
        return;
    }
}

int main ()
{
    int roll_no, value;
    
    do
    {
        std::cout << "Roll No: ";
        std::cin >> roll_no;   
    }while(roll_no / 1000 <= 0);

    value = roll_no % 100;

    int employee_ID[5] = {10, 37, 54, 71, 99};

    binarySearch(employee_ID, 0, 4, value);
}