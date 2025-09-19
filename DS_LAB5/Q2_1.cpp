#include <iostream>

void printNumbers(int n)
{
    std::cout << n << std::endl;
    
    if (n == 1)
    return;
    
    else
    printNumbers(n - 1);
}

int main ()
{
    int n;
    std::cout << "PRINTING FROM N TO 1\ninput nth value: ";
    std::cin >> n;
    
    printNumbers(n);
}