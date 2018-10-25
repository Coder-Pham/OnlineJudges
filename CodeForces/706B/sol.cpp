/**
 * Author: Pham T.Nhan
 * Date: 25/10/2018
 * Link: http://codeforces.com/problemset/problem/706/B
 * Name: Interesting drink
**/

#include <iostream>
#include <vector>
#include <algorithm> // For short, I use short in vector instead of self-built QSort

int n;
std::vector<int> price;

int bisearch_modified(int first, int size, int value)
{
    if (value < price[first])
    {
        return 0;
    }

    int count = size;
    while (count > 1)
    {
        int step = count / 2;
        if (value >= price[first + step])
        {
            first += step;
            count -= step;
        }
        else
            count = step;
    }
    return first + 1;
}

int main(int argc, char const *argv[])
{
    std::cin >> n;
    price.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> price[i];
    }

    std::sort(price.begin(), price.end());

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        int coins;
        std::cin >> coins;

        std::cout << bisearch_modified(0, price.size(), coins) << std::endl;

        // For short
        // std::cout << std::upper_bound(price.begin(), price.end(), coins) - price.begin() << std::endl;
    }

    return 0;
}
