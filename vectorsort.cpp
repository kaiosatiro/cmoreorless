#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n{0};
    vector<int> vec;

    cin >> n;
    cin.ignore();
    while(n--){
        int i;
        cin >> i;
        vec.push_back(i);
    }

    sort(vec.begin(), vec.end());

    for (auto i: vec){
        cout << i << ' ';
    }

    
    return 0;
}
