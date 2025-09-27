#include <iostream>

int ackermann(int m, int n)
{
    if (m == 0)
    return n + 1;

    if (m > 0 && n == 0)
    return ackermann(m - 1, 1);

    if (m > 0 && n > 0)
    return ackermann(m - 1, ackermann(m, n - 1));
    
    else
    return -1;
}

int main ()
{
    int n, m;

    std::cout << "ACKERMANN FUNCTION\ninput n: ";
    std::cin >> n;
    std::cout << " \ninput m: ";
    std::cin >> m;
    
    std::cout << "result: " << ackermann(m, n) << std::endl;
}