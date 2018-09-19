#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Book
{
public:
	// Default constructor and constructor with 3 arguments.
	Book() {};
	Book(string writer, string year, string name): author(writer), date(year), title(name){};
	// Mutators
	void set_author(string writer);
	void set_date(string year);
	void set_title(string name);
	// Accessors
	string get_author();
	string get_date();
	string get_title();
	// Overloaded << operator
	friend ostream& operator <<(ostream& outs, Book bookOne)
	{
		cout << bookOne.author << ". " << bookOne.title << ". " << bookOne.date << ".";
		return outs;
	}
	// < operator, used for sort, returns true if one string is alphabetically 
	// before another string
	friend bool operator < (Book& one, Book& two)
	{        
		return one.author < two.author;
	}
	// < operator, used for sort, returns true if one string is alphabetically 
	//after another string
	friend bool operator > (Book& one, Book& two)
	{        
		return one.author > two.author;
	}
private:
	string author;
	string date;
	string title;
};
#endif