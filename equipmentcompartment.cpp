#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "equipmentcompartment.h"



EquipmentCompartment::EquipmentCompartment(){
		ECSecEmpFlag=false;
		ECMainEmpFlag=false;
		cout << "Equipment compartment just created!" << endl;
	}
	EquipmentCompartment::~EquipmentCompartment(){
		cout << "Equipment compartment to be destroyed" << endl;
	}
	bool EquipmentCompartment::isEqual(Object*){}
	Object* clone(){}
	bool EquipmentCompartment::ready_check(){}

	void EquipmentCompartment::setECSecEmpFlag(bool flag){
		ECSecEmpFlag=flag;
	}
	bool EquipmentCompartment::getECSecEmpFlag(){
		return ECSecEmpFlag;
	}
	void EquipmentCompartment::setECMainEmpFlag(bool flag){
		ECMainEmpFlag=flag;
	}
	bool EquipmentCompartment::getECMainEmpFlag(){
		return ECMainEmpFlag;
	}

	void EquipmentCompartment::process(Employee* e){
		// e->workOn(this);
	}

};