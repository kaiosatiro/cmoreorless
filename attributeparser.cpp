#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

// using namespace std;


// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// </tag2>
// </tag1>

// tag1.tag2~name
// tag1~name
// tag1~value

std::string tag_parser(std::string& str){
    size_t start = str.find('<');
    size_t end = str.find('>');

    std::string tag = str.substr(start +1, end -1);
    
    return tag;
}


void parser(
        int &i, 
        std::vector<std::string> &vec, 
        std::string current_tag = "", 
        std::string tag_tree = ""
){
    if (i >= vec.size())
        return;
    std::string substring = vec[i];

    size_t start = substring.find('<');
    size_t end = substring.find('>');

    std::string tagContent;
    if (start != std::string::npos && end != std::string::npos) {
        tagContent = substring.substr(start + 1, end - 1);
    }




    i++;    
};


int main() {
    int n_lines{0}, queries{0};
    char c;
    std::vector<std::string> lines;
    std::cin >> n_lines >> queries;

    for (int i{0}; i < n_lines; i++){
        std::string temp_str;
        std::getline(std::cin >> std::ws, temp_str);
        lines.push_back(temp_str);
    }

    std::map<std::string, std::string> q_dict;

    int line_n = 0 ;
    do {
        parser(line_n, lines);

    } while (line_n < n_lines); 

    
    return 0;
}

    // std::stringstream stream(vec[i]);
    // std::string word;

    // while (stream >> word){
    //     if (word.find("tag") != std::string::npos){
    //         std::string token = tag_parser(word);
    //         current_tag = token;
    //         if (tag_tree.empty())
    //             tag_tree += token;
    //         else
    //             tag_tree += "." + token;
    //     }
    //     else {
    //         std::cout << word;
    //     }

    // }