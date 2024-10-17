#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
// using namespace std;


int main() {
    int i{0}, query{0}, data{0};

    std::set<int> s;
    std::cin >> i;
    std::cin.ignore();

    while (i--){
        std::cin >> query >> data;

        switch (query) {
            case 1:
                s.insert(data);
                break;
            case 2:
                s.erase(data);
                break;
            case 3:
                if (s.find(data) != s.end())
                    std::cout << "Yes" << std::endl;
                else
                    std::cout << "No" << std::endl;
            default:
                continue;
        }
    }
    return 0;
}



