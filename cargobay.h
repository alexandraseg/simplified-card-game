#include "privatecompartment.h"
class EquipmentCompartment;

class CargoBay::public PrivateCompartment{
private:
	EquipmentCompartment* EquipCompOfCargoBay;
	bool CBSecEmpFlag;
	bool CBMainEmpFlag;
	bool CBCleanEmpFlag;
public:
	CargoBay::CargoBay();
	~CargoBay();
	bool isEqual(Object*);
	Object* clone();
	bool ready_check();
	void setCBSecEmpFlag(bool flag);
	bool getCBSecEmpFlag();
	void setCBMainEmpFlag(bool flag);
	bool getCBMainEmpFlag();
	void setCBCleanEmpFlag(bool flag);
	bool getCBCleanEmpFlag();
	void process(Employee*);
};