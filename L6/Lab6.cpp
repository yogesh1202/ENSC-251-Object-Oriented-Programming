/**
* @file Lab6.cpp
* @author Yogesh Mundhra
* @Date 29th June 2018
* @version 1.0
* @section This program converts 24 hour time entered by a user to 12 hour time
*		   and throws an exception if an incorrect time is entered
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Yogesh Mundhra ____ _____29th June 2018______________
//
// ____ 301346798 ______
//
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// This is the exception class which stores the respective error message 
// depending on the error occuring.
class TimeFormatMistake
{
public:
	// Default constructor and error message, this is called upon with no arguments 
	// and displays the formatting error message
	TimeFormatMistake()
	{
		message = "Formatting error, please enter 2 integers separated by a colon\ni.e. 23:59";
	}
	// This is the constructor that takes in one argument
	// The main function calls upon this when there is an issue with the
	// range of numbers entered.
	TimeFormatMistake(int hours)
	{
		message = "Invalid numbers.\nPlease enter an hour between 00 and 23 and minute between 00 and 59";
	}
	// Accessor for the message, returns a string.
	string getMessage()
	{
		return message;
	}
private:
	string message;
};
int main()
{
	int hours=0;
	int minutes=0;
	char colon='\0';
	bool eChar=false;
	char exitC='\0';
	// This do while allows users to continue the program endlessly
	// depending on what character they enter on the exit prompt.
	do
	{
		cout <<"Enter time in 24-hour notation: ";
		// This try block is the program without any errors
		try
		{
			cin >> hours >> colon >> minutes;
			// If the format is wrong and a wrong type of character is entered
			// this if block throws the default constructor
			if(cin.fail() || colon!=':')
			{
				cin.clear();
				cin.ignore(1000,'\n');
				throw TimeFormatMistake();
			}
			// If the numbers entered are out of range 
			// this if block throws the constructor with one int input
			if ((hours>=24 || hours<0) || (minutes<0 || minutes>=60))
			{
				throw TimeFormatMistake(hours);
			}
			// Default program if all input is correctly formatted
			if (hours < 12 && hours >= 0)
			{
				// Fills one digit integers with zeros where required
				cout << "That is the same as\n" << setfill('0')  << setw(2) << hours
					 << colon << setfill('0')  << setw(2) << minutes << " AM"<< endl;
			}
			//PM time
			if (hours >= 12 && hours < 24 )
			{
				// This deals with the non-extreme case where hours equals 12
				if(hours!=12)
				{
					hours = hours - 12;
				}
					cout << "That is the same as\n" << setfill('0')  << setw(2) << hours
						 << colon << setfill('0')  << setw(2) << minutes << " PM"<< endl;
			}
			// Prompts user whether they want to continue or exit the program
			cout << "Do you want to continue?\n(y for yes, any other character for no): ";
			cin >> exitC;
			// Reads the exit character and continues if it's a y
			if(exitC == 'y' || exitC == 'Y')
			{
				continue;
			}
			else
			{
				eChar = true;
			}
		}
		// This catch block uses the accessor function getMessage()
		// to show the corresponding message
		catch(TimeFormatMistake e)
		{
			cout << e.getMessage() << endl;
		}
	}
	while(eChar == false);
	cout << "Program ended.";
	return 0;
}
