/**
* @file lab8.cpp
* @author YOGESH MUNDHRA
* @Date 20th July 2018
* @version 1.0
* @section This program reads a comma delimited .csv file which contains historic stock info for
*		   Apple from Yahoo! Finance. It then outputs two files sorted in ascending and descending
*		   order of the high values. It also displays monthly averages, yearly averages, yearly highs 
*          and lows
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ YOGESH MUNDHRA ____ _____20th July 2018______________
//
// ____ 301346798 ______
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Stock.h"
using namespace std;
string intToMonth(int i);
// Overloaded unary operator < to use for sorting algorithm
// This function compares the high values for two Stock objects
bool operator < (Stock& lhs, Stock& rhs) 
    {
         return lhs.getHigh() < rhs.getHigh();
    }
int main()
{
	ifstream inFile;
	ofstream outFile;
	string dummy="\0";
	int lowest = 4000;
	int highest = 0;
	int countDays = 0;
	int daysInMonth = 0;
	double sumYear = 0.0;
	double average = 0.0;
	double sumMonth = 0.0;
	double monthAverage = 0.0;
	//Creates two vectors, for sorting and for processing.
	vector <Stock> stockv;
	vector <Stock> sortv;
	//Opens file StockPrices.csv
	//Program works as long as file is called StockPrices.csv
	//Can easily change into a user prompt for file if needed
	inFile.open("StockPrices.csv");
	if(inFile.fail())
	{
		cerr << "Error: file could not be opened. Ensure the file is called StockPrices.csv";
		exit(1);
	}
	//Captures first line with titles and skips to the next one
	getline(inFile, dummy);
	// In this while loop, an object of the type Stock is created and 
	// data from the file is inserted into it and pushed to the vectors
	while(inFile)
	{	
		Stock tempSto;
		inFile >> tempSto;
		// This is to ignore any null data
		if(tempSto.getDate() == 0)
		{
			continue;
		}
		stockv.push_back(tempSto);
		sortv.push_back(tempSto);
	}
	sort(sortv.begin(), sortv.end());
	//Creates an output file for ascending order
	outFile.open("lowToHigh.csv");
	//Writes titles
	outFile << dummy << endl;
	// In this for loop, the iterator goes through the vector and sends one line
	// of data to the file.
	for(vector<Stock>::iterator p = sortv.begin() ; p!= sortv.end() ; p++)
	{
		// The following if statements capture the first and last year in the file
		// These are called lowest and highest and are used later
		if(p->getDate() < lowest)
		{
			lowest = p->getDate();
		}
		if(p->getDate() > highest)
		{
			highest = p->getDate();
		}
		outFile << *p;
		outFile << endl;
	}
	// Closes output file and opens new one for descending order
	outFile.close();
	outFile.open("highToLow.csv");
	// Writes titles 
	outFile << dummy << endl;
	// For this for loop, we use the reverse iterator to output the descending order
	for(vector<Stock>::reverse_iterator it = sortv.rbegin(); it!= sortv.rend(); it++)
	{
		outFile << *it;
		outFile << endl;
	}
	//Closes output file.
	outFile.close();
	// Creates two dynamic arrays with lengths equal to the greatest year + 1
	double *lowYear, *highYear;
	lowYear = new double[highest + 1];
	highYear = new double[highest + 1];
	// This for loop initializes the two arrays, which are used to store the lowest
	// and highest high values through the year.
	for(int ii = 0; ii <= highest; ii++)
	{
		// The low year is initialized to 1 million
		// The high year is initialized to 0 so any stock above it registers
		lowYear[ii] = 1000000.00;
		highYear[ii] = 0;
	}
	// This for loop goes through the years from lowest year in file to highest year.
	for(int i = lowest; i <= highest; i++)
	{
		// This for loop goes through the months of the year
		for(int j = 1; j < 13; j++)
		{
			// This for loop uses the iterator itt to go through the vector with Stock objects
			for(vector<Stock>::iterator itt = stockv.begin(); itt!= stockv.end(); itt++)
			{
				// This if loop verifies we are still in the year we are checking through
				if(itt->getDate() == i)
				{
					// Adds high values through the year each time
					// and counts the number of days there are values for.
					sumYear += itt->getHigh();
					countDays++;
					//Verifies we are in the same month then counts 
					// the days we have values for and sums values
					if(itt->getMonth() == j)
					{
						daysInMonth++;
						sumMonth += itt->getHigh();
					}
					//Sets the highest high values
					if(itt->getHigh() > highYear[i])
					{
						highYear[i] = itt->getHigh();
					}
					//Sets the the lowest high values in the year
					if(itt->getHigh() < lowYear[i])
					{
						lowYear[i] = itt->getHigh();
					}
				}
			}			
			// Checks for division by zero error and sets the monthly
			// average to zero if so, calculates the average otherwise
			// Only displays average for months that have values
			if (daysInMonth != 0)
			{
				monthAverage = sumMonth/daysInMonth;
				cout << "The monthly average for " << intToMonth(j) << " of " << i << " is " 
					 << fixed << setprecision(4) << monthAverage << endl;
			}
			else
			{
				monthAverage = 0;
			}
			// Resets the days and total high counter
			daysInMonth = 0;
			sumMonth = 0;
		}
		// Calculates yearly average and only displays it for years that have a value
		// if no days have values then the average is reset to zero
		if(countDays != 0)
		{
			average = sumYear/countDays;
			cout << "The yearly average for " << i << " is: " << average << endl;
			cout << "The high for " << i << " is: " << highYear[i] << endl;
			cout << "The low for " << i << " is: " << lowYear[i] << endl << endl;
		}
		else
		{
			average = 0;
		}
		// Resets counters for days and the total sum of high values
		countDays = 0;
		sumYear = 0;
	}
	// Returns heap memory
	delete [] lowYear;
	delete [] highYear;
	return 0;
}
/**
* @brief This function converts an integer value to its respective month
* @param int i is the month input 
* @return string the month itself
*/
string intToMonth(int i)
{
	// This is a simple switch statement that returns the respective
	// string to display for the monthly average statements
	switch (i)
	{
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8: 
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "Error: Invalid month";
	}
}