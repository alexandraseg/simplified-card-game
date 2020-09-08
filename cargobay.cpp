#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "cargobay.h"


CargoBay::CargoBay(){
		CBSecEmpFlag=false; 
		CBMainEmpFlag=false;
		CBCleanEmpFlag=false;
		EquipCompOfCargoBay=new EquipmentCompartment();
		cout << "Cargo Bay just created!" << endl;
	}

	CargoBay::~CargoBay(){
		cout << "Cargo Bay to be destroyed" << endl;
	}
	bool CargoBay::isEqual(Object*){}
	Object* CargoBay::clone(){} //ο κλωνοποιημένος δείκτης να δείχνει σε καινούριο αντικείμενο
	bool CargoBay::ready_check(){}

	void CargoBay::setCBSecEmpFlag(bool flag){
		CBSecEmpFlag=flag;
	}
	bool CargoBay::getCBSecEmpFlag(){
		return CBSecEmpFlag;
	}

	void CargoBay::setCBMainEmpFlag(bool flag){
		CBMainEmpFlag=flag;
	}
	bool CargoBay::getCBMainEmpFlag(){
		return CBMainEmpFlag;
	}

	void CargoBay::setCBCleanEmpFlag(bool flag){
		CBCleanEmpFlag=flag;
	}
	bool CargoBay::getCBCleanEmpFlag(){
		return CBCleanEmpFlag;
	}

	void CargoBay::process(Employee* e){
		e->workOn(this);
	}