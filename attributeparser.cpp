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

std::string* attribute_parser(std::string& attribute, std::stringstream& stream){
    static std::string pair[2];
    std::string dump, value;

    pair[0] = attribute;  
    stream >> dump;
    stream >> value;

    size_t start = value.find('"');
    size_t end = value.find_last_of('"');

    pair[1] = value.substr(start +1, end -1);    

    return pair;
}

std::string tag_parser(std::string& str){
    size_t start = str.find('<');
    size_t end = str.find('>');

    std::string tag = str.substr(start +1, end -1);
    return tag;
}


void parser(
        int &iterator, 
        std::vector<std::string> &hrml_vec,
        std::map<std::string, std::string> &query_map,
        std::string current_tag = "", 
        std::string tag_tree = "",
        int tag_tree_lenght = 0
){  

    if (iterator == hrml_vec.size())
        return;
    
    std::stringstream stream(hrml_vec[iterator]);
    std::string word;

    while (stream >> word){
        if (word.find("</") != std::string::npos){
            int tag_sep = tag_tree.find_last_of('.');
            if (tag_sep != std::string::npos)
                tag_tree.erase(tag_sep);
            // else
            //     tag_tree.clear();
            continue;
        }
        
        else if (word.find("<") != std::string::npos){
            current_tag = tag_parser(word);
            
            if (tag_tree_lenght == 0) 
                tag_tree += current_tag;
            else 
                tag_tree += "." + current_tag;
            tag_tree_lenght++;
        }
        else {
            std::string* att_value_pair = attribute_parser(word, stream);
            std::string query = tag_tree + "~" + att_value_pair[0];
            query_map[query] = att_value_pair[1];
        }
    }

    iterator++;
    parser(iterator, hrml_vec, query_map, current_tag, tag_tree, tag_tree_lenght);
};


int main() {
    int hrml_len{0}, n_queries{0};
    char c;
    std::vector<std::string> hrml_lines;
    std::vector<std::string> query_lines;
    std::cin >> hrml_len >> n_queries;

    for (int i{0}; i < hrml_len; i++){
        std::string temp_str;
        std::getline(std::cin >> std::ws, temp_str);
        hrml_lines.push_back(temp_str);
    }

    std::map<std::string, std::string> query_dict;

    int line_n = 0 ;
    do {
        parser(line_n, hrml_lines, query_dict);

    } while (line_n < hrml_len); 

    // for (auto const& pair: query_dict){
    //     std::cout << pair.first << " : " << pair.second << std::endl;
    // }
    
    for (int i{0}; i < n_queries; i++){
        std::string temp_str;
        std::getline(std::cin >> std::ws, temp_str);
        query_lines.push_back(temp_str);
    }

    for (auto const& query: query_lines){
        if (query_dict.find(query) == query_dict.end())
            std::cout << "Not Found!" << std::endl;
        else
            std::cout << query_dict[query] << std::endl;
    }
   
    return 0;
}
