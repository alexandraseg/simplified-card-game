#include "planecomponent.h"

class PassengerCompartment:public PlaneComponent{
private:
	PassengerCompartment* interiorPassengerCompartment;
	bool PCSecEmpFlag;
	bool PCCleanEmpFlag;
	
public:
	PassengerCompartment(bool flag);
	~PassengerCompartment();
	void setPCSecEmpFlag(bool);
	bool getPCSecEmpFlag();
	void setPCCleanEmpFlag(bool flag);
	bool getPCCleanEmpFlag();
	void process(Employee* e);
	bool isEqual(Object*);
	Object* clone();
	bool ready_check();
	String* toString();


};