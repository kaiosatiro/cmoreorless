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
    while (n--)
    {
        int i;
        cin >> i;
        vec.push_back(i);
    }

    int q1;
    cin >> q1;
    cin.ignore();
    vec.erase(vec.begin() + q1 -1);


    int q2a, q2b;

    cin >> q2a >> q2b;
    cin.ignore();
    vec.erase(vec.begin() + q2a -1, vec.begin() + q2b -1);

    cout << vec.size() << '\n';

    for(auto i: vec)
        cout << i << ' ';
    
    return 0;
}
