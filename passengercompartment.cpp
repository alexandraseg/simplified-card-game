#include <iostream>
#include <random>
#include "passengercompartment.h"

using namespace std;
	
PassengerCompartment::PassengerCompartment(bool flag=true)
	{	
		PCSecEmpFlag=false;
		PCCleanEmpFlag=false;
		interiorPassengerCompartment=nullptr;

		if (flag==true){ //flag used to create only one interior passenger compartment
		std::random_device rd; // obtain a random number from hardware
    	std::mt19937 eng(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, 1); 
		int randomNumber=distr(eng); 
		if (randomNumber==1){
			interiorPassengerCompartment=new PassengerCompartment(false);
		}
		}
		cout << "Passenger compartment just created!" << endl;
	}

	PassengerCompartment::~PassengerCompartment(){
		cout << "Passenger compartment to be destroyed" << endl;
	}
	void PassengerCompartment::setPCSecEmpFlag(bool flag){
		PCSecEmpFlag=flag;
	}
	bool PassengerCompartment::getPCSecEmpFlag(){
		return PCSecEmpFlag;
	}
	void PassengerCompartment::setPCCleanEmpFlag(bool flag){
		PCCleanEmpFlag=flag;
	}
	bool PassengerCompartment::getPCCleanEmpFlag(){
	 	return PCCleanEmpFlag;
	 }
	 void PassengerCompartment::process(Employee* e){
		e->workOn(this);
		if (interiorPassengerCompartment!=nullptr){
			interiorPassengerCompartment->process(e);
		}
	}

	bool PassengerCompartment::isEqual(Object*){}
	Object* PassengerCompartment::clone(){}
	bool PassengerCompartment::ready_check(){
		if ((PCSecEmpFlag==true) && (PCCleanEmpFlag==true)){
			cout << "Passenger Compartment OK!" << endl;
			if (interiorPassengerCompartment!=nullptr){
				if ((interiorPassengerCompartment->getPCSecEmpFlag()==true) && (interiorPassengerCompartment->getPCCleanEmpFlag()==true)){
					cout << "Interior Passenger Compartment OK!" << endl;
					return true;
				}else{
					return false;
				}
			}
			return true;
		}else{
			return false;
		}
	}

	String* PassengerCompartment::toString(){}
