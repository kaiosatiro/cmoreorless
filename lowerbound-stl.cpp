#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int n{0};
    std::vector<int> vec;
    
    std::cin >> n; std::cin.ignore();
    while (n--)
    {
        int i;
        std::cin >> i;
        vec.push_back(i);
    }

    int q{0};
    std::cin >> q; std::cin.ignore();

    while (q--)
    {
        int qn;
        std::cin >> qn;
        std::vector<int>::iterator low;
        low = std::lower_bound(vec.begin(), vec.end(), qn);

        bool cnt;
        if (qn == vec.at(low - vec.begin()))
            cnt = true;
        else
            cnt = false;

        std::cout << (cnt ? "Yes " : "No ") << (low - vec.begin() +1) << '\n';
    }
    
    return 0;
}
