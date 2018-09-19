/**
* @file Lab4.cpp
* @author YOGESH MUNDHRA
* @date   8th June 2018
* @version 1.0
* @section This program creates a class called Pairs which contains overloaded operators
*		   The program asks the user to enter two pairs of numbers and outputs the result 
*		   of element-wise multiplication, addition and subtraction.
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others.  I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____Yogesh Mundhra____      _____8th June 2018______________
//
// ____ 301346798 ______
#include <iostream>
using namespace std;
class Pairs
{
private:
    int f;
    int s;
public:
	// Default Constructor, initializes pair to (0,0)
    Pairs()
    {
        f = 0;
        s = 0;
    };
	// Constructor with one variable
    Pairs(int first)
    {
        f = first;
        s = 0;
    };
	// Constructor with two arguments
    Pairs(int first, int second)
    {
        f = first;
        s = second;
    };
    //other members and friends
    friend istream& operator >> (istream& ins, Pairs& second);
    friend ostream& operator << (ostream& outs, const Pairs& second);
    friend Pairs operator + (Pairs&first, Pairs&second);
    friend Pairs operator -(Pairs&first, Pairs&second);
    friend Pairs operator *(Pairs&first, Pairs&second);
    
};
int main()
{
	// This test program initializes three pairs using different constructors
	Pairs pairOne;
	Pairs pairTwo(3);
	Pairs pairThree(4,5);
	// It then creates two default Pairs
	Pairs pairFour;
	Pairs pairFive;
	cout << "Object constructed with no argument: ";
	cout << pairOne << endl;
	cout << "Object constructed with one argument (e.g. 3): ";
	cout << pairTwo << endl;
	cout << "Object constructed with two arguments (e.g. 4,5): ";
	cout << pairThree << endl;
	// Prompts user for input
	cout << "Enter a pair in the format (a,b): ";
	cin >> pairFour;
	cout << "Enter another pair in the format (c,d): ";
	cin >> pairFive;
	// Replaces example objects' values with new values
		// for * operator
	pairOne=pairFour*pairFive;
	cout << "(a,b) * c = ";
	cout << pairOne << endl;
		//for + operator
	pairTwo=pairFour+pairFive;
	cout << "(a,b) + (c,d) = ";
	cout << pairTwo << endl;
		//for - operator
	pairThree=pairFour-pairFive;
	cout << "(a,b) - (c,d) = ";
	cout << pairThree << endl;
	return 0;
}
/**
* @brief This is the overloaded operator >>, that takes in two numbers in the form (a,b)
*		 and verifies input for formatting.
* @param istream &ins, Pairs &second
* @return istream
*/
istream& operator >> (istream& ins, Pairs& second)
{
    char fBrack = '\0';
    char sBrack = '\0';
    char comma = '\0';
    bool exitFlag = false;
	/* 
	This do while loop checks for invalid format of input and asks
	the user to enter it again if not correct.
	*/
        do
        {
			// Reads 6 characters including the brackets and commas.
			// The brackets and commas are stored temporarily.
            ins >> fBrack >> second.f >> comma >> second.s >> sBrack;
			//Compares the stored chars to const chars
            if(fBrack!='(' || comma!=',' || sBrack!=')' || ins.fail())
            {
				// Outputs error if incorrect and clears input stream.
                cerr << "Incorrect format, please enter it in the format (a,b): ";
                ins.clear();
                ins.ignore(16,'\n');
            }
			else
            {
				// This allows the code to run outside the loop
                exitFlag = true;
            }
        } 
		while (exitFlag == false);
    return ins;
}
/**
* @brief This is the overloaded operator << that outputs the two stored integers
* @param ostream& outs, Pairs& second
* @return Pairs&
*/
ostream& operator << (ostream& outs, const Pairs& second)
{
    outs << "(" << second.f << "," << second.s << ")";
    return outs;
}
/**
* @brief This is the overloaded operator + that adds two pairs
* @param Pairs &first, Pairs& second
* @return Pairs&
*/
Pairs operator +(Pairs& first, Pairs& second)
{
    Pairs temp;
    temp.f = first.f + second.f;
    temp.s = first.s + second.s;
    return temp;
}
/**
* @brief This is the overloaded operator - that subracts one pair from another
* @param Pairs &first, Pairs& second
* @return Pairs
*/
Pairs operator -(Pairs& first, Pairs& second)
{
    Pairs temp;
    temp.f = first.f - second.f;
    temp.s = first.s - second.s;
    return temp;
}
/**
* @brief This is the overloaded operator * that multiplies one pair's first int
*		 with another pairs elements
* @param Pairs &first, Pairs& second
* @return Pairs
*/
Pairs operator *(Pairs& first, Pairs& second)
{
    Pairs temp;
    temp.f = first.f * second.f;
    temp.s = first.s * second.s;
    return temp;
}
