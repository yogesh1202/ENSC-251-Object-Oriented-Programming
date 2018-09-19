#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
// Defining the class Stock
class Stock
{
public:
	// Default Constructor
	Stock(): day(0), month(0), year(0), open(0.0), high(0.0), low(0.0), close(0.0), adj(0.0), volume(0.0){}
	// Constructor with arguments
	Stock(int mon, int day2, int yr, double op, double hi, double lo, double clo, double ad, double vol): 
		day(day2), month(mon), year(yr), open(op), high(hi), low(lo), close(clo),
		adj(ad), volume(vol){}
	// Overloaded insertion operator to read into object
	friend istream& operator >>(istream& input, Stock &theStock)
	{
		char comma=',';
		// Works fine for comma delimited files with 7 columns
		input >> theStock.month >> comma >> theStock.day 
		>> comma >> theStock.year >> comma >> theStock.open 
		>> comma >> theStock.high >> comma >> theStock.low 
		>> comma >> theStock.close >> comma >> theStock.adj 
		>> comma >> theStock.volume;
		return input;
	}
	// Overloaded output operator to output to file/display
	// Formats it as presented in csv file
	friend ostream& operator <<(ostream& output, const Stock theStock)
	{
		char comma = ',';
		char slash = '/';
		output << theStock.month << slash << theStock.day << slash 
			<< theStock.year << comma << theStock.open << comma 
			<< theStock.high << comma << theStock.low << comma 
			<< theStock.close << comma << theStock.adj << comma 
			<< theStock.volume;
		return output;
	}
	// Accessor for year
	int getDate()
	{
		return year;
	}
	// Accessor for month
	int getMonth()
	{
		return month;
	}
	// Accessor for day
	int getDays()
	{
		return day;
	}
	// Accessor for high value
	double getHigh()
	{
		return high;
	}
private:
   int day;
   int month;
   int year;
   double  open;
   double  high;
   double  low;
   double  close;
   double  adj;
   double  volume;
};
#endif