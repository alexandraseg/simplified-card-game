#include <iostream>

using namespace std;

class a {
public:
    a() {
        cout << "constructor called" << endl;
    };  
    a(const a& other) { 
        cout << "copy constructor called" << endl;
    };    
    a& operator=(const a& other) {
        cout << "copy assignment operator called" << endl;
        return *this; 
    };
};

int main()
{
a b; //constructor
a c; //constructor
b = c; //copy assignment
c = a(b); //copy constructor, then copy assignment

	return 0;
}