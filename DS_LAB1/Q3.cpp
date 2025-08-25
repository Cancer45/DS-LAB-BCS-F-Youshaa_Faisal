#include <iostream>

class Box
{
    int* integers = nullptr;
    int num_integers = 0;
    
    public:
    Box() {}
    
    //copy constructor implemented as deep copy
    Box(const Box& other_box)
    {
        this->num_integers = other_box.num_integers;
        this->integers = new int[this->num_integers];
        
        for (int i = 0; i < this->num_integers; i++)
        {
            this->integers[i] = other_box.integers[i];
        }
    }
    
    //copy assignment operator implemented as shallow copy
    Box operator= (const Box& other_box)
    {
        this->num_integers = other_box.num_integers;
        this->integers = other_box.integers;
        
        return *this;
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
   Box box1;
   
   box1.addIntegers(45);
   box1.addIntegers(-3);
   box1.addIntegers(1001);
   
   //deep copy
   Box box2(box1);
   
   //shallow copy
   Box box3;
   
   box3 = box1;

    //shallow copy causes memory issues, code executes successfully without shallow copy
}
