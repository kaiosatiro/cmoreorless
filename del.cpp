#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pyramid(string str);

int main()
{   
    string str;

    cout << "Enter any string: ";
    getline(cin, str);

    pyramid(str);
    return 0;
}

void pyramid(string str)
{
    size_t p_size = str.length();
    size_t spc_size = p_size - 1;

    vector<char> chars_in_line{};

    for (int l{0}; l < p_size; l++){
        cout << string(spc_size, ' ');
        chars_in_line.push_back(str[l]);
        for (auto c: chars_in_line)
            cout << c;
        for (int r{chars_in_line.size() - 2}; r >= 0; r--)
            cout << chars_in_line.at(r);
        cout << '\n';
        spc_size--;
    }

}