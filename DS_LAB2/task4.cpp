#include <iostream>

class DynamicArray
{
    float* array = nullptr;
    unsigned int size;

    public:
    DynamicArray(unsigned int size) : size(size)
    {
        array = new float[size];

        for (int i = 0; i < size; i++)
        this->array[i] = 0;
    }

    ~DynamicArray()
    {
        delete [] array;
    }

    bool expandArray(unsigned int new_size)
    {
        if (new_size <= size)
        {
            std::cout << "new size must be greater than " << size << std::endl;
            return false;
        }

        float* tmp_array = new float[new_size];

        for (int i = 0; i < size; i++)
        tmp_array[i] = array[i];

        delete [] array;
        array = tmp_array;

        size = new_size;

        return true;
    }

    void setValue(float value, unsigned int index)
    {
        array[index] = value;
    }

    float getAverage()
    {
        float average = getTotal();
        average /= size;
        return average;
    }

    float getTotal()
    {
        float total = 0;
        for (int i = 0; i < size; i++)
        total += array[i];

        return total;
    }
};

int main ()
{
    std::cout << "EXPENSES TRACKER\n";

    unsigned int num_months;
    std::cout << "Number of Months: ";
    std::cin >> num_months;

    DynamicArray tracker(num_months);

    float expense;
    for (int i = 0; i < num_months; i++)
    {
        std::cout << "Month " << i + 1 << " Expense: ";
        std::cin >> expense;

        tracker.setValue(expense, i);
    }

    unsigned int ans;

    unsigned int new_months;
    while(1)
    {
        std::cout << "\nTrack more Expenses(1)\nDisplay Average and Quit(2 or other key)\n";
        std::cin >> ans;

        if (ans != 1)
        {
            std::cout << "\nTotal: " << tracker.getTotal() << std::endl;
            std::cout << "Average: " << tracker.getAverage() << std::endl;
            
            std::cout << "QUITTING...";
            return 0;
        }

        do
        {
            std::cout << "Number of Months: ";
            std::cin >> new_months;
        }while(tracker.expandArray(new_months));
        
        for (int i = num_months; i < new_months; i++)
        {
            std::cout << "Month " << i + 1 << " Expense: ";
            std::cin >> expense;
            
            tracker.setValue(expense, i);
        }
        
    }
}