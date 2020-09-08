#include <iostream> 
#include <random>
#include "passengercompartment.h"

using namespace std;

class String;

class Object;

class Employee;

class PassengerCompartment;

class PrivateCompartment:public PlaneComponent{
public:
	PrivateCompartment(){
		cout << "Private compartment just created!" << endl;
	}
	~PrivateCompartment(){
		cout << "Private compartment to be destroyed" << endl;
	}
};

class EquipmentCompartment:public PrivateCompartment{
private:
	bool ECSecEmpFlag;
	bool ECMainEmpFlag;
public:
	EquipmentCompartment(){
		ECSecEmpFlag=false;
		ECMainEmpFlag=false;
		cout << "Equipment compartment just created!" << endl;
	}
	~EquipmentCompartment(){
		cout << "Equipment compartment to be destroyed" << endl;
	}
	bool isEqual(Object*){}
	Object* clone(){}
	bool ready_check(){
		if ((ECSecEmpFlag==true) && (ECMainEmpFlag==true)){
			cout << "Equipment Compartment OK!" << endl;
			return true;
		}else{
			return false;
		}
	}

	void setECSecEmpFlag(bool flag){
		ECSecEmpFlag=flag;
	}
	bool getECSecEmpFlag(){
		return ECSecEmpFlag;
	}
	void setECMainEmpFlag(bool flag){
		ECMainEmpFlag=flag;
	}
	bool getECMainEmpFlag(){
		return ECMainEmpFlag;
	}

	void process(Employee* e){
		e->workOn(this);
	}

};

class CargoBay:public PrivateCompartment{
private:
	EquipmentCompartment* EquipCompOfCargoBay;
	bool CBSecEmpFlag;
	bool CBMainEmpFlag;
	bool CBCleanEmpFlag;
public:
	CargoBay(){
		CBSecEmpFlag=false; 
		CBMainEmpFlag=false;
		CBCleanEmpFlag=false;
		EquipCompOfCargoBay=new EquipmentCompartment();
		cout << "Cargo Bay just created!" << endl;
	}
	~CargoBay(){
		cout << "Cargo Bay to be destroyed" << endl;
	}
	bool isEqual(Object*){}
	Object* clone(){} //ο κλωνοποιημένος δείκτης να δείχνει σε καινούριο αντικείμενο
	bool ready_check(){
		if ((CBSecEmpFlag==true) && (CBMainEmpFlag==true) && (CBCleanEmpFlag==true)){
			cout << "Cargo Bay OK!" << endl;
			if (EquipCompOfCargoBay->ready_check()==true){
				cout << "Equipment Compartmet of Cargo Bay OK!" << endl;
				return true;
			}
			else{
				return false;
			}
		}else{
			return false;
		}

	}

	void setCBSecEmpFlag(bool flag){
		CBSecEmpFlag=flag;
	}
	bool getCBSecEmpFlag(){
		return CBSecEmpFlag;
	}

	void setCBMainEmpFlag(bool flag){
		CBMainEmpFlag=flag;
	}
	bool getCBMainEmpFlag(){
		return CBMainEmpFlag;
	}

	void setCBCleanEmpFlag(bool flag){
		CBCleanEmpFlag=flag;
	}
	bool getCBCleanEmpFlag(){
		return CBCleanEmpFlag;
	}

	void process(Employee* e){
		e->workOn(this);
		EquipCompOfCargoBay->process(e);
	}

	String* toString(){}
};


class SecurityEmployee:public Employee{
public:
	SecurityEmployee(){
		cout << "Security employee just created!" << endl;
	}
	~SecurityEmployee(){
		cout << "Security employee to be destroyed" << endl;
	}
	void report(){cout << "I worked on security" << endl;}

	void workOn(PassengerCompartment* passCompart){

	 	if (passCompart->getPCSecEmpFlag()==false){
		this->report();
	 	passCompart->setPCSecEmpFlag(true);
		 }
	}

	void workOn(EquipmentCompartment* equipCompart){
		if (equipCompart->getECSecEmpFlag()==false){
		this->report();
	 	equipCompart->setECSecEmpFlag(true);
		 }
	}

	void workOn(CargoBay* cargoBayCompart){
		if (cargoBayCompart->getCBSecEmpFlag()==false){
		this->report();
	 	cargoBayCompart->setCBSecEmpFlag(true);
		 }
	}

};

class MaintenanceEmployee:public Employee{
public:
	MaintenanceEmployee(){
		cout << "Maintenance employee just created!" << endl;
	}
	~MaintenanceEmployee(){
		cout << "Maintenance employee to be destroyed" << endl;
	}
	void report(){cout << "I worked on maintenance" << endl;}
	void workOn(EquipmentCompartment* equiComp){
	 	if (equiComp->getECMainEmpFlag()==false){
	 	this->report();
	 	equiComp->setECMainEmpFlag(true);
	 }
	}

	void workOn(CargoBay* cargoBayCompart){
		if (cargoBayCompart->getCBMainEmpFlag()==false){
	 	this->report();
	 	cargoBayCompart->setCBMainEmpFlag(true);
		}
	}

	void workOn(PassengerCompartment* passComp){//doesn't do anything
	}
};

class CleaningEmployee: public Employee{
public:
	CleaningEmployee(){
		cout << "Cleaning employee just created!" << endl;
	}
	~CleaningEmployee(){
		cout << "Cleaning employee to be destroyed" << endl;
	}
	void report(){cout << "I cleaned" << endl;}
	void workOn(PassengerCompartment* passCompart){

		if (passCompart->getPCCleanEmpFlag()==false){
			this->report();
		 	passCompart->setPCCleanEmpFlag(true);
		 }
	}
	void workOn(CargoBay* cargBa){

		 if (cargBa->getCBCleanEmpFlag()==false){
			 this->report();
			 cargBa->setCBCleanEmpFlag(true);
	 	}
	}

	void workOn(EquipmentCompartment* eqCom){//doesn't do anything
	}
};


class Plane:public Object{
private:
	String title;
	CargoBay* CargoBayPlane;
	EquipmentCompartment* EquipmentCompartmentPlane[2];
	vector <PassengerCompartment*> PassengerCompartmentPlane;
	int capacity;
	int numberOfPassengerComparments;
	

public:
	Plane(int planeCapacity=90):capacity(planeCapacity){
		
		CargoBayPlane=new CargoBay();

		for (int i=0; i<2; i++){
			EquipmentCompartmentPlane[i]=new EquipmentCompartment();
		}
		
		//random number in a range
		std::random_device rd; // obtain a random number from hardware
    	std::mt19937 eng(rd()); // seed the generator
    	
    	// std::uniform_int_distribution<> distr(1, 4); // define the range
        //std::cout << distr(eng) << endl; // generate numbers


		if (planeCapacity<90){
			PassengerCompartmentPlane.push_back(new PassengerCompartment(true));
			numberOfPassengerComparments=1;
		}else if (planeCapacity<200){

			std::uniform_int_distribution<> distr(1, 2);
			int randomNumber=distr(eng); 
			numberOfPassengerComparments=randomNumber;

			for (int i=0; i<randomNumber; i++){
				PassengerCompartmentPlane.push_back(new PassengerCompartment(true));
			}

		}else{

			std::uniform_int_distribution<> distr(2, 3); 
			int randomNumber=distr(eng); 
			numberOfPassengerComparments=randomNumber;

			for (int i=0; i<randomNumber; i++){
				PassengerCompartmentPlane.push_back(new PassengerCompartment(true));
			}
		}
		cout << "Plane just created!" << endl;}
	~Plane(){
		PassengerCompartmentPlane.clear();
		cout << "Plane to be destroyed" << endl;}
	void setTitleofPlane(string aTitle){this->title.setString(aTitle);} 
	String getTitleofPlane(){return title;}
	void setCapacity(int mycapacity){this->capacity=mycapacity;}
	int getCapacity(){return this->capacity;}
	int getNumberOfPassengerCompartments(){return PassengerCompartmentPlane.size();}

	String* toString(){

		String* aString=new String; 
		aString->setString("Plane's title is ");
		string planeTitle=title.getString();
		aString->setString(aString->concatenateStrings(planeTitle));
		aString->setString(aString->concatenateStrings(" ,its capacity is "));
		int planeCapacity=getCapacity();
		string capacityConvertedToString=to_string(planeCapacity);
		aString->setString(aString->concatenateStrings(capacityConvertedToString));
		aString->setString(aString->concatenateStrings(" ,and it has ")); 
		int planePasCompartments=getNumberOfPassengerCompartments();
		string numPasCompConvToString=to_string(planePasCompartments);
		aString->setString(aString->concatenateStrings(numPasCompConvToString));
		aString->setString(aString->concatenateStrings(" passenger compartments."));
		return aString;
	}

	String* clone(){}

	bool isEqual(Object* myObject){}
	
	virtual bool ready_check(){
		if ((CargoBayPlane->ready_check()==true) && (EquipmentCompartmentPlane[0]->ready_check()==true) && (EquipmentCompartmentPlane[1]->ready_check()==true)) {
			int k=0;
			for (int i=0; i<numberOfPassengerComparments; i++){
				if (PassengerCompartmentPlane.at(i)->ready_check()==true){
					k++;
				}
			}
			if (k==numberOfPassengerComparments){
				cout << "Plane ready to take off!" << endl;
				return true;
			}
			else{
				return false;
			}

		}
		else{
			return false;
		}

	}

	virtual void process(Employee* anEmp){
		CargoBayPlane->process(anEmp);
		for (int i=0; i<2; i++){
			EquipmentCompartmentPlane[i]->process(anEmp);
		}
		int vectorCapacity=getCapacity();
		 if (vectorCapacity=1){
			PassengerCompartment* PasCompPlane;
			PasCompPlane=PassengerCompartmentPlane.at(0);
		 	(*PasCompPlane).process(anEmp);
		 }else if (vectorCapacity=2){
		 	for (int j=0; j<2; j++){
		 		PassengerCompartment* PasCompPlane;
		 		PasCompPlane=PassengerCompartmentPlane.at(j);
		 		(*PasCompPlane).process(anEmp);
		 	}
		 }else if (vectorCapacity=3){
		 	for (int k=0; k<3; k++){
		 		PassengerCompartment* PasCompPlane;
		 		PasCompPlane=PassengerCompartmentPlane.at(k);
		 		(*PasCompPlane).process(anEmp);
		 	}

		}
	}


};


int main(){
	String myfirstStringObject;
	myfirstStringObject.setString("1st message");
	String* ptrToString=new String;
	ptrToString=myfirstStringObject.toString();
	ptrToString->printString();
	delete ptrToString;

	Plane myPlane(10);


	SecurityEmployee* mySecurityEmployee = new SecurityEmployee();
	MaintenanceEmployee* myMaintenanceEmployee = new MaintenanceEmployee();
	CleaningEmployee* myCleaningEmployee = new CleaningEmployee();
	
	myPlane.process(mySecurityEmployee);
	myPlane.process(myMaintenanceEmployee);
	myPlane.process(myCleaningEmployee);

	myPlane.ready_check();

	delete myCleaningEmployee;
	delete mySecurityEmployee;
	delete myMaintenanceEmployee;

	return 0;
}