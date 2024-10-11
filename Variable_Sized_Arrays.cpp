#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n{};
    int k{};
    int number{};
    int q1{}, q2{};

    cin >> n >> k;
    vector<vector<int>> matrix(n, vector<int>(0));
    vector<vector<int>> queries(k, vector<int>(0));

    for (int i{0}; i < n; i++){
        while (cin >> number) {
            matrix[i].push_back(number);
            if (cin.peek() == '\n')
                break;
        }
    }

    for (int i{0}; i < k; i++){
        cin >> q1 >> q2;
        queries[i].push_back(q1);
        queries[i].push_back(q2+1);
    }

    for (auto q: queries){
        cout << matrix[q[0]][q[1]] << endl;
    }

    return 0;
}