#include "object.h"
using namespace std;

class String:public Object{

private:
	std::string myString;

public:
	String();
	~String();
	void setString(string aString);
	string getString();
	size_t getLengthOfString();
	void clearString();
	void printString();
	char& getCharAtSpecPosit(size_t pos);
	string& updateCharAtSpecPosit(size_t, const string&, size_t);
	string concatenateStrings(const string&);
	string concatenateStrings(const char*);
	String* toString();
	String* clone();
	bool isEqual(Object*);

};