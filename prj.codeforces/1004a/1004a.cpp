#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, d, otv = 2;
    std::cin >> n >> d;
    std::vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (vec[i + 1] - vec[i] == 2 * d)
        {
            otv += 1;
        }

        if (vec[i + 1] - vec[i] > 2 * d)
        {
            otv += 2;
        }
    }
std:cout << otv;
}