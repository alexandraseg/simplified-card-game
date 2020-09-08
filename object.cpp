#include <iostream> 
#include <string>
#include <vector>
#include <random>
#include "string.h"

using namespace std;

void Object::setId(int myId){id=myId;}

Object::Object(){
	id=++idProvider;
	cout << "Object just created!" << endl;}
Object::~Object(){cout << "Object to be destroyed" << endl;}
	int Object::getId(){return id;}
bool Object::isIdentical(Object* myObject){
	if (myObject=this){
		return true;
	}else{
		return false;
	}
}

String* Object::toString(){
		String* aString=new String;
		aString->setString("Object's id is");
		int id=Object::getId();
		std::string idConvertedToString=to_string(id);
		aString->setString(aString->concatenateStrings(idConvertedToString));
		// aString->concatenateStrings(idConvertedToString);
		return aString;
	}

int Object::idProvider=0;