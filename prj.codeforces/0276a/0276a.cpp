#include <iostream>
int main()
{
    int n, k, max_ud, f1, t1;
    std::cin >> n >> k;
    
    std::cin >> f1 >> t1;
    if (t1 > k)
    {
        f1 = f1 - (t1 - k);
    }
    max_ud = f1;

    for (int i = 1; i < n; i++)
    {
        int fi, ti;
        std::cin >> fi >> ti;
        if (ti > k)
        {
            fi = fi - (ti - k);
        }

        if (fi > max_ud)
        {
            max_ud = fi;
        }
    }
    std::cout << max_ud;
}