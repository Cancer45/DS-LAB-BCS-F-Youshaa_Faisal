#include <iostream>

void printMultipleOf2(int n);
void printMultipleOf3(int n)
{
    std::cout << n << ": " << n * 3 << std::endl;
    
    if (n == 1)
    return;
    
    else
    printMultipleOf2(n - 1);
}

void printMultipleOf2(int n)
{
    std::cout << n << ": " << n * 2 << std::endl;
    
    if (n == 1)
    return;
    
    else
    printMultipleOf3(n - 1);
}

int main ()
{
    int n, start;
    std::cout << "PRINTING MULTIPLES OF 2 AND 3 ALTERNATIVELY \ninput nth value: ";
    std::cin >> n;
    
    do
    {
        std::cout << "start with: ";
        std::cin >> start;
    }while(start != 2 && start != 3);
    
    
    if (start == 2)
    printMultipleOf2(n);
    
    else
    printMultipleOf3(n);
}