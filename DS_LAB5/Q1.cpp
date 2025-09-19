#include <iostream>

int calculateFactorial(int n)
{
    if (n == 1)
    return 1;
    
    else return n * calculateFactorial( n - 1);
}

int main ()
{
    int n;
    std::cout << "COMPUTING THE Nth FACTORIAL\ninput nth value: ";
    std::cin >> n;
    
    n = calculateFactorial(n);
    std::cout << "nth factorial: " << n << std::endl;
    
}