#include "privatecompartment.h"

class EquipmentCompartment:public PrivateCompartment{
private:
	bool ECSecEmpFlag;
	bool ECMainEmpFlag;
public:
	EquipmentCompartment();
	~EquipmentCompartment();
	bool isEqual(Object*);
	Object* clone();
	bool ready_check();

	void setECSecEmpFlag(bool flag);
	bool getECSecEmpFlag();
	void setECMainEmpFlag(bool flag);
	bool getECMainEmpFlag();
	void process(Employee* e);

};

