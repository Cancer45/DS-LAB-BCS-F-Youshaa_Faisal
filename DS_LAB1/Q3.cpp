#include <iostream>

class Box
{
    int* integers = nullptr;
    int num_integers = 0;
    
    public:
    Box() {}
    Box(const Box& other_box)
    {
        this->num_integers = other_box.num_integers;
        this->integers = new int[this->num_integers];
        
        for (int i = 0; i < this->num_integers; i++)
        {
            this->integers[i] = other_box.integers[i];
        }
    }
    
    Box operator= (const Box& other_box)
    {
        this->num_integers = other_box.num_integers;
        this->integers = new int[this->num_integers];
        
        for (int i = 0; i < this->num_integers; i++)
        {
            this->integers[i] = other_box.integers[i];
        }
    }
    ~Box()
    {
        if (integers != nullptr)
        delete [] integers;
    }
    
    void addIntegers(int new_integer)
    {
        int* tmp_integers = new int[num_integers + 1];
        
        for (int i = 0; i < num_integers; i++)
        {
            tmp_integers[i] = integers[i];
        }
        
        tmp_integers[num_integers] = new_integer;
        
        if (integers != nullptr)
        delete [] integers;
        
        integers = tmp_integers;
        
        num_integers++;
    }
};

int main ()
{
   
}