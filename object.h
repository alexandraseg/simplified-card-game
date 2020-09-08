
class String;

class Object{
private:
	int id;
	static int idProvider;

protected:
	void setId(int); //protected so that it can be used by functions-members of the derived classes, without being public

public:
	Object();
	~Object();
	int getId();
	virtual bool isEqual(Object*)=0; //pure virtual function to force the derived classes to override the function and provide their own implementation
	//function needs to "return true" or "false"
	virtual bool isIdentical(Object*);
	virtual Object* clone()=0; //θα πρέπει να γίνει delete η δυναμική δέσμευση
	virtual String* toString()=0;
};
