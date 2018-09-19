/**
* @file HW3b.cpp
* @author Yogesh Mundhra
* @Date 05th July 2018
* @version 1.0
* @section This program allows the user to create a stack of specified size
*		   and allows the user to input characters in to add to this stack
*		   it throws an overflow exception and empty exception 
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
//Declares a structure called Stackframe which contains a node with one char
//and a pointer to the next character in the stack
struct StackFrame
{
	 char data;
	 StackFrame *link;
};
// Renames StackFrame* to StackFramePtr for ease of use;
typedef StackFrame* StackFramePtr;
class Stack
{
public:
	//Default constructor
	Stack();
	//Constructor with one integer argument
	Stack(int maximum);
	//Destructor
	~Stack();
	char pop();
	void add(char letter);
	bool empty() const;
private:
	StackFramePtr head;
	int counter;
	int maxSize;
};
class StackOverFlowException
{
public:
	// Default constructor and error message, this sets the message
	StackOverFlowException()
	{
		message = "Stack overflow, can not add anymore. Program ended.";
	}
	// Accessor function for retrieving error message
	string getMessage()
	{
		return message;
	}
private:
	string message;
};
class StackEmptyException
{
public:
	// Default constructor and error message, this sets the message
	StackEmptyException()
	{
		message = "Stack is empty, can not remove node. Program ended.";
	}
	// Accessor function for retrieving error message
	string getMessage()
	{
		return message;
	}
private:
	string message;
};

int main()
{
	char c1;
	int size;
	int num;
	bool valid=true;
	// Allows user to enter value for the size of the stack
	cout << "Enter a maximum size: ";
	cin >> size;
	// Creates two Stack objects, one default and one with user specified size
	Stack s1(size), s2;
	cout << "Creating a stack of size " << size << endl;
	// This while loop runs until the user stops or an exception is thrown
	 while(valid)
	 {
		cout << "Enter 1 to add a character, 0 to remove a character, any other character to end: ";
		cin >> num;
		//If the user enters a wrong character, the program breaks out.
		if(cin.fail() || (num!=1 && num!=0))
		{
			break;
		}
		if(num==1)
		{
			cout << "Enter character to add: ";
			cin >> c1;
			s1.add(c1);
			continue;
		}
		if(num==0)
		{
			s1.pop();
		}
	}
	cout << "Program ended.";
	return 0;
}
// This is the default constructor which sets the maximum size to 10 characters
Stack::Stack(): head(NULL), counter(0), maxSize(10){};
// This is the constructor with one argument that is the user defined size
Stack::Stack(int maximum): head(NULL), counter(0), maxSize(maximum){};
// Destructor
Stack::~Stack()
{
	char next;
	//This while loop removes all characters to free up memory
	//until the stack is empty
	while(!empty())
		next = pop();
}
/**
* @brief Returns true if the stack is empty and false if not
* @param void
* @return bool
*/
bool Stack::empty() const
{
	return (head == NULL);
}
/**
* @brief Adds new character to the top of the stack. "push" function
* @param char letter is the letter passed by the user
* @return void
*/
void Stack::add(char letter)
{
	// This try block is the default run of the program
	try
	{
		// If the counter value is equal to the maximum size
		// throw overflowexception.
		if(counter >= maxSize)
		{
			throw StackOverFlowException();
		}
		// Increments counter
		counter++;
		//Creates new pointer, and points it to a new node
		//then assigns the letter to the temp data and makes it the head
		StackFramePtr temp_ptr;
		temp_ptr = new StackFrame;
		temp_ptr->data = letter;
		temp_ptr->link = head;
		head = temp_ptr;
	}
	//The catch block displays the respective message\
	//and exits the program.
	catch(StackOverFlowException e)
	{
		cout << e.getMessage() << endl;
		exit(1);
	}
}
/**
* @brief Removes character from the top of the stack. "pop" function
* @param void
* @return char 
*/
char Stack::pop()
{
	try
	{
		if(empty())
		{
			throw StackEmptyException();
		}
		counter--;
		char result = head->data;
		StackFramePtr tempPtr;
		tempPtr = head;
		head = head->link;
		delete tempPtr;
		cout << "Removed: " << result << endl;
		return result;
	}
	catch(StackEmptyException e)
	{
		cout << e.getMessage() << endl;
		exit(1);
	}
}