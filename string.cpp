#include <iostream> 
#include <string>
#include <vector>
#include <random>
#include "string.h"

using namespace std;



String::String(){
	cout << "String just created!" << endl;}


	String::~String(){cout << "String to be destroyed" << endl;}

	void String::setString(std::string aString){this->myString=aString;}
	std::string String::getString(){return this->myString;}
	size_t String::getLengthOfString(){return this->myString.length();}
	void String::clearString(){this->myString.clear();}
	void String::printString(){cout<< this->myString << endl;}
	char& String::getCharAtSpecPosit(size_t pos){ return this->myString.at(pos);}
	std::string& String::updateCharAtSpecPosit(size_t pos, const std::string& str, size_t len=1){return this->myString.replace(pos, len, str);}
	std::string String::concatenateStrings(const std::string& rhs){
		return this->myString+" "+rhs;}
	std::string String::concatenateStrings(const char* rhs){return this->myString+" "+rhs;} //overloading
	
	String* String::toString(){
		String* aString=new String; //object's id to string
		String* objectString=Object::toString();
		aString->setString(objectString->getString());
		aString->setString(aString->concatenateStrings("and <String>'s member is:"));
		aString->setString((aString->concatenateStrings(this->getString())));
		return aString;
	 }

	 String* String::clone(){
	 	std::string MyStringInitial=this->getString();
	 	String* aStringClone=new String;
	 	aStringClone->setString(MyStringInitial);
	 	int idInitial=Object::getId();
	 	aStringClone->setId(idInitial);
	 	return aStringClone;
	 }

	bool String::isEqual(Object* myObject){
		String* s=dynamic_cast<String*>(myObject); //checking if the pointer is pointing to a string object
		if (s){ // if not null, then it's a string object
			if (s->getId()==this->getId()) { //comparing objects' ids and if they are identical it compares their member's value
				if (s->getString()==this->getString()){
					return true;
				}

			} else{
				return false;
			}
		}else{
			return false;
		}

	}
	