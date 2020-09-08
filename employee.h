#include "string.h"

class PassengerCompartment;
class CargoBay;
class EquipmentCompartment;

class Employee:public Object{
private:
public:
	Employee();
	~Employee();
	virtual void report()=0;
	
	virtual void workOn(PassengerCompartment*)=0;
	virtual void workOn(CargoBay*)=0;
	virtual void workOn(EquipmentCompartment*)=0;

	bool isEqual(Object*);
	Object* clone();
	String* toString();
};