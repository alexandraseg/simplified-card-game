#include "employee.h"

class PlaneComponent:public Object{
private:
	bool flagCompReady;
	Employee* EmployeeOfTheComponent;
public:
	PlaneComponent();
	~PlaneComponent();
	void setFlagCompReady(bool);
	bool getFlagCompReady();
	String* toString();
	virtual void process(Employee* e)=0;
	virtual bool ready_check()=0;

};
