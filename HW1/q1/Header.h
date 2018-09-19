/**
 * @file Header.h
 * @author Yogesh Mundhra
 * @date   5/31/2018
 * @version 1.0
 *
 * @brief <ENSC 251, Homework 1a>
 *
 * @section This is a header file containing the class needed for the first question
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ YOGESH MUNDHRA ____      _____31st May 2018______________
//
// ____ 301346798 ______
#ifndef HW1A_H
#define HW1A_H
#include <string>
using namespace std;
class Player
{
private:
    int compChoice;
    int playerChoice;
    string playerName;
public:
	//Default constructor
    Player()
    {
		playerName = "Player 1";
    }
	void numGen();
	char checkWinner();
	// Accessor and mutator for player's name
	void setPlayerName(string name)
    {
		playerName = name;
    }
	string getPlayerName()
    {
		return playerName;
    }
	// Accessors and Mutators for computer choice and player choice
    void setComputerChoice(int computerChoice)
    {
		compChoice = computerChoice;
    }
    void setPlayerChoice(int userChoice)
    {
		playerChoice = userChoice;
    }
    int getPlayerChoice()
    {
		return playerChoice;
    }
    int getCompChoice()
    {
		return compChoice;
    }
};
#endif