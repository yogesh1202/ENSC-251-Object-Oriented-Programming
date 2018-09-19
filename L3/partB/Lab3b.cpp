/**
* @file Lab3b.cpp
* @author YOGESH MUNDHRA
* @date   1st June 2018
* @version 1.0
* @section Creates class called Car and shows the car speed increasing then decreasing
*		   using member functions accelerate and brake
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others.  I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Yogesh Mundhra____      _____1st June 2018______________
//
// ____ 301346798 ______

#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
// Member variables include two variables of type int and one string
    int yearModel;
    string make;
    int speed;
public:
	// Constructor only uses 2 arguments, the int yearModel and the string make
	// Initializes speed variable to 0
    Car(int yearMo, string makeType)
    {
        yearModel = yearMo;
        make = makeType;
        speed = 0;
    }
	// Accessors, which return value of private member variables
    int getYearModel()
    {
        return yearModel;
    }
    string getMake()
    {
        return make;
    }
    int getSpeed()
    {
        return speed;
    }
	// Member function which adds 5 to the speed variable
    void accelerate()
    {
        speed += 5;
    }
	// Member function which subtracts 5 from the speed variable;
    void brake()
    {
        speed -= 5;
    }
	//outputSpeed which displays current speed of car
	//takes in an input of type Car (object)
    void outputSpeed(Car&newCar)
    {
        cout << "The speed is now " << newCar.getSpeed() << endl;
    }
};
// Main function
int main()
{
	// Creates new object called toyota with model year 1998 and make sedan
    Car toyota(1998,"Sedan");
	// for loop that adds 5 to the speed for 5 times and displays current speed
    for(int i=1; i<=5; i++)
    {
        toyota.accelerate();
        toyota.outputSpeed(toyota);
    }
	// for loop that subtracs 5 from the speed for 5 times and displays current speed
    for(int j=1; j<=5; j++)
    {
        toyota.brake();
        toyota.outputSpeed(toyota);
    }
    return 0;
}
