/**
* @file HW3a.cpp
* @author Yogesh Mundhra
* @Date 05th July 2018
* @version 1.0
* @section This program tests inherited classes. It creates
*		   a Vehicle class and a child class called Truck from it
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Yogesh Mundhra ____ _____05th July 2018______________
//
// ____301346798______
#include <iostream>
#include <string>
using namespace std;
// This class definition was provided in the question
class Person
{
public:
	Person();
	Person(string theName);
	Person(const Person& theObject);
	string getName() const;
	Person& operator = (const Person& rtSide)
	{
		(*this).name = rtSide.name;
        return *this;
	}
	friend istream& operator >>(istream& inStream, Person& personObject)
	{
		inStream >> personObject.name;
		return inStream;
	}
	friend ostream& operator <<(ostream& outStream, const Person& personObject)
	{
		outStream << personObject.name;
		return outStream;
	}
private:
	string name;
};
// Base class Vehicle
class Vehicle
{
public:
	//Default Constructor
	Vehicle();
	// Constructor with 3 arguments
	Vehicle(string manufacturer, int cyl, const Person& driver);
	//Copy Constructor
	Vehicle(const Vehicle& theObject);
	// function to print data
	void printVehicle();
	// The following is the definition for the overloaded assignment operator.
	Vehicle& operator = (const Vehicle& rtSide)
	{
		//Assigns manufacturer name, number of cylinders and owner name to "this"
		//Returns this
		this->manuName = rtSide.manuName;
		this->cylinders = rtSide.cylinders;
		this->owner = rtSide.owner;
		return *this;
	}
	// Accessors
	string get_manuName();
	int get_cylinders();	
	Person get_owner();
	// Mutators
	void set_manuName(string manu);
	void set_cylinders(int cyl);
	void set_owner(Person keys);
private:
    string manuName;
    int cylinders;
    Person owner;
};
// Derived class Truck
class Truck : public Vehicle
{
public:
	// On top of all functions and members from Vehicle
	// The truck has the following members:
	// Default constructor
	Truck();
	// Constructor with 5 arguments
	Truck(string manufacturer, int cyl, const Person& driver, double load, int tow);
	// Copy constructor
	Truck(const Truck& truckOne);
	// Overloaded assignment operator
	Truck& operator =(const Truck& rtSide)
	{
		// Calls upon the Vehicle operator to assign all the variables of vehicle
		Vehicle::operator =(rtSide);
		// assigns towing and loading capacity of its own
		towCap = rtSide.towCap;
		loadCap = rtSide.loadCap;
		return *this;
	}
	// Function to print truck details 
	void printTruck();
	// accessors
	double getLoadCap();
	int getTowCap();
	// mutators
	void setLoadCap(double load);
	void setTowCap(int tow);
private:
    double loadCap;
    int towCap;
};
// Person Implementation
Person::Person(): name("No name"){} //Default constructor
Person::Person(string theName): name(theName){} //Constructor with name
Person::Person(const Person& theObject): name(theObject.name){} // copy constructor
string Person::getName() const 
{
	return name;
}
//Default constructor
Vehicle::Vehicle(): manuName("Unnamed Manufacturer"), cylinders(0), owner("No name"){}
//Constructor with 3 arguments.
Vehicle::Vehicle(string manufacturer, int cyl, const Person& driver): 
					owner(driver), manuName(manufacturer), cylinders(cyl){};
//Print function
void Vehicle::printVehicle()
{
		cout << "Vehicle information: \n";
		cout << "Owner: " << get_owner() << endl;
		cout << "Number of cylinders: " << get_cylinders() << endl;
		cout << "Manufacturer: " << get_manuName() << endl;
}
string Vehicle::get_manuName()
{
	return manuName;
}
int Vehicle::get_cylinders()
{
	return cylinders;
}
Person Vehicle::get_owner()
{
	return owner;
}
void Vehicle::set_manuName(string manu)
{
	manuName = manu;
}
void Vehicle::set_cylinders(int cyl)
{
	cylinders = cyl;
}
void Vehicle::set_owner(Person keys)
{
	owner = keys;
}
//Copy Constructor
Vehicle::Vehicle(const Vehicle& theObject): manuName(theObject.manuName), 
					cylinders(theObject.cylinders), owner(theObject.owner){};
// Default constructor for Truck
Truck::Truck(): loadCap(0.0), towCap(0){};
// Constructor with 5 arguments for truck, inherits from Vehicle.
Truck::Truck(string manufacturer, int cyl, const Person& driver, double load, int tow): 
			Vehicle(manufacturer, cyl, driver), loadCap(load), towCap(tow){};
Truck::Truck(const Truck &truckOne): Vehicle(truckOne), towCap(truckOne.towCap)
						,loadCap(truckOne.loadCap){};
// Prints general Vehicle first and then truck details
void Truck::printTruck()
{
		printVehicle();
		cout << "Vehicle type: Truck" << endl;
		cout << "Load capacity (tons): " << getLoadCap() << endl;
		cout << "Tow capacity (pounds): " << getTowCap() << endl;
}
double Truck::getLoadCap()
{
	return loadCap;
}
int Truck::getTowCap()
{
	return towCap;
}
void Truck::setLoadCap(double load)
{
	loadCap = load;
}
void Truck::setTowCap(int tow)
{
	towCap = tow;
}
int main()
{
	//Creates a Person object dName.
	Person dName;
	string first, last;
	int cylinders;
	string make;
	//Starts user input construction
	cout << "Please enter the name (first and last): ";
	cin >> first >> last;
	// Uses overloaded assignment operator on dName.
	dName = first +" " + last;
	cout << "Please enter vehicle name: ";
	cin >> make;
	cout << "Please enter the number of cylinders: ";
	cin >> cylinders;
	// Creates a vehicle object with user provided details
	Vehicle veh(make, cylinders, dName);
	cout << "This is the vehicle you have entered details for: \n";
	veh.printVehicle();
	cout << endl;
	//Testing Truck constructor with random arguments and printing using print Truck.
	cout << "Testing constructor with arguments for Truck with random details: \n";
	Truck t("Honda",4,Person("Nikola Tesla"),45.1,24);
	t.printTruck();
	cout << endl;
	// Testing Default Constructors and printing them out
	cout << "Now testing default constructors for both Truck and Vehicle: \n";
	Vehicle temp;
	Truck temp2;
	temp.printVehicle();
	cout << endl;
	temp2.printTruck();
	return 0;
}
