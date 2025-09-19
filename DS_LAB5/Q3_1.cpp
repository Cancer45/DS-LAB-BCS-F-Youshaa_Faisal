#include <iostream>

int sumTail(int n, int sum)
{
    if (n == 0)
    return sum;
    
    return sumTail(n - 1, n + sum);
}

//tail recursion sums at each new call before calling with one less

int main ()
{
    int n, sum;
    std::cout << "SUM TAIL TO 0\ninput nth value: ";
    std::cin >> n;
    
    sum = sumTail(n, 0);
    std::cout << "sum: " << sum << std::endl;
    
}