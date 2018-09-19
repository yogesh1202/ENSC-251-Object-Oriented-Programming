/**
* @file Lab3a.cpp
* @author YOGESH MUNDHRA
* @date   1st June 2018
* @version 1.0
* @section This program creates two classes called Patient and Procedure
*		   which store a patient's files and a procedure done on the patient
*		   This program then displays to the user these details.
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others.  I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____Yogesh Mundhra____      _____1st June 2018______________
//
// ____ 301346798 ______
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Patient{
private:
	// Member variables, also includes an additional fullName string variable
    string firstName;
    string middleName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNum;
    string emergName;
    string emergPhone;
    string fullName;
public:
	// Constructor for Patient, includes 10 arguments in string format
    Patient(string one, string two, string three,
            string four, string five, string six, string seven,
            string eight, string nine, string ten)
            {
				// Assigning arguments to private member variables
                firstName = one;
                middleName = two;
                lastName = three;
                fullName = one +" "+ two +" "+ three;
                address = four;
                city = five;
                state = six;
                zip = seven;
                phoneNum = eight;
                emergName = nine;
                emergPhone = ten;
            }
	// Accessors, return value of specific variable on request.
    string getFirst()
    {
        return firstName;
    }
    string getMiddle()
    {
        return middleName;
    }
    string getLast()
    {
        return lastName;
    }
    string getAddress()
    {
        return address;
    }
    string getCity()
    {
        return city;
    }
    string getState()
    {
        return state;
    }
    string getZip()
    {
        return zip;
    }
    string getPhone()
    {
        return phoneNum;
    }
    string getEmergName()
    {
        return emergName;
    }
    string getEmergPhone()
    {
        return emergPhone;
    }
    string getFullName()
    {
        return fullName;
    }
	// Mutators, change value of private member variables on request.
    void setFirst(string first)
    {
        firstName = first;
    }
    void setMiddle(string middle)
    {
        middleName = middle;
    }
    void setLast(string last)
    {
        lastName = last;
    }
    void setAdd(string addr)
    {
        address = addr;
    }
    void setCity(string cityN)
    {
        city = cityN;
    }
    void setState(string stateN)
    {
        state = stateN;
    }
    void setZip(string zipcode)
    {
        zip = zipcode;
    }
    void setPhone(string phoneN)
    {
        phoneNum = phoneNum;
    }
    void setEmergName(string emergNm)
    {
        emergName = emergNm;
    }
    void setEmergPhone(string emergP)
    {
        emergPhone = emergP;
    }
};
// Beginning of procedure class

class Procedure
{
private:
	//Includes three string variables and one variable stored as a double.
    string name;
    string date;
    string pracName;
    double charges;
public:
	//Constructor for Procedure, using 4 arguments
    Procedure(string proc, string dt, string prac, double chrg)
    {
		// Assigning arguments to private member variables
        name = proc;
        date = dt;
        pracName = prac;
        charges = chrg;
    }
	// Mutators, change value of private member variables to argument value.
    void setProc(string proc)
    {
        name = proc;
    }
    void setDate(string dt)
    {
        date = dt;
    }
    void setPrac(string prac)
    {
        pracName = prac;
    }
    void setCharges(double chrg)
    {
        charges = chrg;
    }
	// Accessors, return value of specific variable on request.
    string getProc()
    {
        return name;
    }
    string getDate()
    {
        return date;
    }
    string getPrac()
    {
        return pracName;
    }
    double getCharges()
    {
        return charges;
    }
};
// Main function
int main()
{
	// Constructs a sample object
	// All arguments in string format
    Patient patientOne("Christopher", "Edwin", "Breaux","420 Park Avenue",
                       "New York","New York","07306","+19197781202",
                       "Katonya Breaux","+19198893452");
	// Given sample procedure objects stored in 3 different objects
	// First three arguments are strings and the last argument is a double
    Procedure procOne("Physical Exam","1st June 2018","Dr. Irvine",250.00);
    Procedure procTwo("X-ray","1st June 2018","Dr. Jamison",500.00);
    Procedure procThree("Blood test","1st June 2018","Dr. Smith",200.00);

	//Displaying information about Patient
    cout << "Patient information:" << endl;
    cout << "Name: " << patientOne.getFullName() << endl;
    cout << "Address: " << patientOne.getAddress() << ", "
         << patientOne.getCity() << ", " << patientOne.getState()
         << ", " << patientOne.getZip() << "." << endl
         << "Phone number: " << patientOne.getPhone() << endl;

	//Displaying Emergency Contact information
    cout << endl << "Emergency Contact Information:\n"
         << "Name: " << patientOne.getEmergName() << endl
         << "Phone: " << patientOne.getEmergPhone() << endl << endl;

	//Displaying information about the 3 different procedures.
	//Line 1
    cout << "Procedure #1\t\t" << "Procedure #2\t\t" << "Procedure #3\n";
    cout << "Procedure name: \t" << "Procedure name: \t" << 
   	    "Procedure name: \t\t" << endl;
	//Line 2 
    cout << procOne.getProc() << "\t\t" << procTwo.getProc() << "\t\t\t" 
	 << procThree.getProc() << "\t\t" << endl;
	//Line 3
    cout << "Date: \t\t\t" << "Date: \t\t\t" << "Date: " << endl
	 << procOne.getDate() << "\t\t" << procTwo.getDate() << "\t\t" 
	 << procThree.getDate();
	//Line 4
    cout << endl << "Charge: $" << fixed << setprecision(2) << procOne.getCharges();
    cout << "\t\t" << "Charge: $" << procTwo.getCharges();
    cout << "\t\t" << "Charge: $" << procThree.getCharges();
	//Line 5
	//Displays total charges by adding the costs from all three procedures
    cout << endl << "Total charges: $" 
	 << procOne.getCharges() + procTwo.getCharges() + procThree.getCharges()
	 << endl;
    return 0;
}
