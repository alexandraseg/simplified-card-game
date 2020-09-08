#include <iostream>
#include "employee.h"


using namespace std;
	
	Employee::Employee(){
		cout << "Employee just created!" << endl;
	}
	Employee::~Employee(){
		cout << "Employee to be destroyed" << endl;
	}

	bool Employee::isEqual(Object*){}
	Object* Employee::clone(){} 
	String* Employee::toString(){}