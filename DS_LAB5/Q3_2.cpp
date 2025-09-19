#include <iostream>

void sumNonTail(int n, int& sum)
{
    if (n == 0)
    return;
    
    sumNonTail(n - 1, sum);
    sum += n;
}

/*non-tail recursion sums after each call returns as opposed to a
tail implementation which sums at every new recursive call*/

int main ()
{
    int n, sum = 0;
    std::cout << "SUM NONTAIL TO 0\ninput nth value: ";
    std::cin >> n;
    
    sumNonTail(n, sum);
    std::cout << "sum: " << sum << std::endl;
    
}