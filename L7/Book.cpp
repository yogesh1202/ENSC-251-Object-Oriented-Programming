/**
* @file Source.cpp
* @author YOGESH MUNDHRA
* @Date 09/07/2018
* @version 1.0
* @section This program allows the user to create a library by entering book data
*			into a vector and be able to see it in alphabetical order
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ YOGESH MUNDHRA ____ _____09/07/2018______________
//
// ____ 301346798 ______
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Book.h"
using namespace std;
int main()
{
	// To store objects of the class Book, we need a vector, we call this library.
	vector <Book> library;
	bool valid = true;
	int choice = 0;
	string temptitle = "\0";
	string tempdate = "\0";
	string tempauthor = "\0";
	// This while loop works as long as a boolean valid which is initialized true, is true.
	while(valid)
	{
		cout << "Select from the following choices:\n";
		cout << "1. Add new book\n";
		cout << "2. Print listing sorted by author\n";
		cout << "3. Quit\n";
		// This takes the user's input and clears anything that may be extra
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');
		// This checks to see if a valid choice has been entered or whether the input stream
		// has a valid entry at all
		if(cin.fail() || (choice!=1 && choice!=2 && choice !=3))
		{
			cout << "Invalid choice. Please enter a valid number for choice.\n";
			continue;
		}
		// If the user selects 1, it prompts them to enter the details
		else if (choice == 1)
		{
			cout << "Enter title of the book:\n";
			getline(cin, temptitle);
			cout << "Enter author's name (Lastname, Firstname)\n";
			getline(cin, tempauthor);
			cout << "Enter publication year:\n";
			getline(cin,tempdate);
			// Creates a temporary object called Book, which is then pushed into the library vector
			Book tempBook(tempauthor, tempdate, temptitle);
			library.push_back(tempBook);
			// Resets choice to -1 for the next run of the program.
			choice = -1;
			continue;
		}
		// If the user selects 2, it prints out the vector, sorted alphabetically
		else if (choice == 2)
		{
			// Uses the sort algorithm to sort the library alphabetically
			sort(library.begin(), library.end());
			cout << "The books entered so far, sorted alphabetically by author are:\n";
			// In this for loop, we create an iterator it, which is our position in the vector
			// Through this, we can print the value at the position of the iterator, which is the book object
			// since I have overloaded the << operator, it is easy to print the Book object
			for(vector <Book>::iterator it = library.begin(); it!=library.end(); it++)
			{
				cout << *it << endl;
			}
			// Resets choice to -1 for the next run of the program.
			choice = -1;
			continue;
		}
		// If the user selects 3, the program ends.
		else if (choice == 3)
		{
			cout << "Program ended. Thank you.";
			break;
		}
	}
	return 0;
}