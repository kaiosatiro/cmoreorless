#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;


int main() {
    std::string input;
    std::vector<int> vec;

    std::getline(std::cin, input);
    std::stringstream ss(input);

    int i{0};
    char c;
    while (ss >> i) {
        vec.push_back(i);
        ss >> c;
    };

    for (auto n: vec)
        cout << n << endl;
        
    return 0;
}
