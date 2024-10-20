#include <map>
#include <iostream>


int main(){
    int Q{0}, operation{0}, mark{0};
    std::string name;

    std::map<std::string, int> dict;

    std::cin >> Q;
    std::cin.ignore();

    while (Q--){
        std::cin >> operation >> name;
        if (operation == 1)
            std::cin >> mark;
        std::cin.ignore();

        switch (operation)
        {
        case 1:
            dict[name] += mark;
            break;
        case 2:
            dict[name] = 0;
            break;
        case 3:
            std::cout << dict[name] << std::endl;
            break;
        default:
            break;
        }

    }
    return 0;
}
