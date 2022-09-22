#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
        vec[i] -= 1 - vec[i] % 2;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << vec[i] << " ";

    }
}