#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    void getdata(){};
    void putdata(){};
};

class Professor: public Person
{
public:
    int cur_id;
    int publications;
    Professor(int id){
        this->cur_id = id;
    }
    void getdata(){
        cin >> this->name >> this->age >> this->publications;
    }
    void putdata(){
        cout << "\n";
        cout << this->name << " ";
        cout << this->age << " ";
        cout << this->publications << " ";
        cout << this->cur_id;
    }

};

class Student: public Person
{
public:
    int cur_id;
    int marks[6];
    Student(int id){
        this->cur_id = id;
    }
    void getdata(){
        cin >> this->name >> this->age;
        int i{0};
        int number{0};
        while (cin >> number && i < 6) {
            this->marks[i] = number;
            if (cin.peek() == '\n')
                break;
            i++;
        }
    }
    void putdata(){
        int sum{0};
        for (int i{0}; i < sizeof(this->marks); i++)
            sum += this->marks[i];

        cout << "\n";
        cout << this->name << " ";
        cout << this->age << " ";
        cout << sum << " ";
        cout << this->cur_id;  
    }
};
// 4
// 1
// Walter 56 99
// 2
// Jesse 18 50 48 97 76 34 98
// 2
// Pinkman 22 10 12 0 18 45 50
// 1
// White 58 87

int main() {
    int n_objects{0};
    int type{0};
    int id{1};

    cin >> n_objects;

    Person* persons[n_objects];

    for (int i{0}; i < n_objects; i++){
        cin >> type;
        if (type == 1){
            persons[i] = &Professor(id);
            (*persons[i]).getdata();
            
        }
        else if (type == 2){
            persons[i] = &Student(id);
            (*persons[i]).getdata();
        }
        id++;
    }

    for (int i{0}; i < sizeof(persons); i++){
        (*persons[i]).putdata();
    }

    return 0;
}
