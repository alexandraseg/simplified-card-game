#include <iostream>
#include "planecomponent.h"

class Employee;
	
PlaneComponent::PlaneComponent(){
		flagCompReady=false;
		cout << "Plane Component just created!" << endl;}
PlaneComponent::~PlaneComponent(){cout << "Plane Component to be destroyed" << endl;}
String* PlaneComponent::toString(){
		String* aString=new String; 
		aString->setString("Plane component's employee is ");
		String* aSecondString=new String;
		aSecondString=EmployeeOfTheComponent->toString();
		aString->setString(aString->concatenateStrings(aSecondString->getString()));
		return aString;
	}
void PlaneComponent::setFlagCompReady(bool isReady){flagCompReady=isReady;}
bool PlaneComponent::getFlagCompReady(){return flagCompReady;}

