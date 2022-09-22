#include <iostream>
int main()
{
    int year;
    std::cin >> year;
    for (int i = year + 1; ; i++)
    {
        int a = i / 1000, b = i % 1000 / 100, c = i % 100 / 10, d = i % 10;
        if (a != b && a != c && a != d)
        {
            if (b != c && b != d)
            {
                if (c != d) {
                    std::cout << i;
                    break;
                }
            }
        }
    }
}