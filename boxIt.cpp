#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
private:
    int l, b, h;
public:
    Box(int l, int b, int h){
        this->l = l;
        this->b = b;
        this->h = h;
    }
    Box() : Box(0, 0, 0){}

    Box(const Box& box) {
        this->l = box.l;
        this->b = box.b;
        this->h = box.h;
    }
    
    friend bool operator< (const Box& box1, const Box& box2){
        if (box1.l < box2.l)
            return true;
        else if (box1.b < box2.b && box1.l == box2.l)
            return true;
        else if (box1.h < box2.h && box1.b == box2.b && box1.l == box2.l)
            return true;
        
        return false;
    }

    friend ostream& operator<< (ostream& os, const Box& box)
    {
        os << box.l << ' ' << box.b << ' ' << box.h;
        return os;
    }

    int getLength(){
        return this->l;
    }
    int getBreadth(){
        return this->b;
    }
    int getHeight(){
        return this->h;
    }
    long long CalculateVolume(){
        return (long) this->l * this->b * this->h;
    }

};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}