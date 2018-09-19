/**
 * @file lab2.cpp
 * @author Yogesh Mundhra
 * @date   5/23/2018
 * @version 1.0
 *
 * @brief <ENSC 251, Lab 2>
 *
 * @section This program converts input names from users to lowercase to Pig Latin
 *
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ YOGESH MUNDHRA ____      _____23rd May 2018______________
//
// ____ 301346798 ______

#include <iostream>
#include <string>

using namespace std;

string firstName();
string lastName();
string lowercase(string inputStr);
string pigLatin(string inputName);

int main()
{

    string first="\0";
    string last="\0";
    string fullName="\0";

    first = firstName();
    last = lastName();
    first = lowercase(first);
    last = lowercase(last);
    first = pigLatin(first);
    last = pigLatin(last);
    fullName = first+" "+last;  //Creates new string with Pig Latin first name and last name together with a space
    cout << fullName << endl;

    return 0;
}

/**
* @brief Retrieves first name and checks for alphabets
* @return string
*/
string firstName()
{

	string firstInput = "\0";
	bool firstValid = false;

    do
    {
        cout << "Please enter your first name: ";
        getline(cin,firstInput);
        //This for loop checks for alphabetical characters only, so no numbers or whitespace is taken in
        for (int i = 0; i<firstInput.length(); i++)
        {
            if (!isalpha(firstInput[i]))
            {
                cout << "Error: Please enter alphabetical characters only\n";
                firstValid = false;
                break;
            }
            if (i == firstInput.length()-1)
            {
                firstValid = true;      //This sets the validity flag to be true so the code can break out of the loop once a valid name is entered
            }
        }
    }
    while (firstValid == false);
    return firstInput;

}

/**
* @brief Retrieves last name and checks for errors in entry
* @return string
*/
string lastName()
{

	bool lastValid = false;
	string secondInput="\0";
	do
	{
		cout << "Please enter your last name: ";
		getline(cin,secondInput);   //Using getline helps

		//This for loop checks for alphabetical characters only, so no numbers or whitespace is taken in
		for (int j=0; j<secondInput.length();j++)
		{
			if (!isalpha(secondInput[j]))
			{
				cout << "Error: Please enter alphabetical characters only\n";
				lastValid = false;
				break;
			}

			if (j == secondInput.length()-1)
			{
				lastValid = true;   //This sets the validity flag to be true so the code can break out of the loop once a valid name is entered
			}
		}
	}

	while (lastValid == false);
	return secondInput;
}

/**
* @brief Converts to lowercase
* @param inputStr is an input string, first name or last name
* @return string
*/
string lowercase(string inputStr)
{
    //This for loops uses tolower and converts all characters to lowercase
    for (int k=0; k<inputStr.length(); k++)
        {
            inputStr[k] = tolower(inputStr[k]);
        }

    return inputStr;
}

/**
* @brief Checks for first letter being a vowel or constant and adds "way" or first character + "ay" at the end of string
* @param inputName is an input string, first name or last name
* @return string
*/
string pigLatin (string inputName)
{
	char firstChar = '\0';      //Temporary character, to be stored as the first letter of the name
    string tempStr="\0";
    //if loop to check for vowels
	if (inputName[0] == 'a' || inputName[0] == 'e' || inputName[0] == 'i' || inputName[0] == 'o' || inputName[0] == 'u')
	{
		inputName = inputName+"way";            //Appends way to name
		inputName[0] = toupper(inputName[0]);   //Converts the first letter to uppercase
	}

	else
	{
		firstChar = tolower(inputName[0]);      //Temporarily stores first character
		//This for loops shifts the second character of the name to the first character
		for(int p=0; p<inputName.length(); p++)
        {
            inputName[p]=inputName[p+1];
        }
		inputName[inputName.length() - 1] = firstChar; //Assigns the first character as the new last digit.
		inputName += "ay";   
		inputName[0] = toupper(inputName[0]);   //Converts new first letter to uppercase
	}

	return inputName;
}
