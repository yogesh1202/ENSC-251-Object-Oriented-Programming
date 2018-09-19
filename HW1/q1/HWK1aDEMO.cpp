/**
 * @file HWK1aDEMO.cpp
 * @author Yogesh Mundhra
 * @date   5/31/2018
 * @version 1.0
 *
 * @brief <ENSC 251, Homework 1a>
 *
 * @section This is a test driver program to showcase the functionalities of the
 *			class
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ YOGESH MUNDHRA ____      _____31st May 2018______________
//
// ____ 301346798 ______
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "Header.h"
using namespace std;
void a_main()
{
	char winChar = '\0';
	Player playerOne; //Initialize test player playerOne
	playerOne.setPlayerName("Alan Turing"); //Set players name
	playerOne.numGen(); //Generate random number
	playerOne.setPlayerChoice(2); //set player choice to 2 (paper)
	winChar = playerOne.checkWinner(); //checks for winner
	cout << playerOne.getPlayerName() << endl; //Shows player name
	cout << playerOne.getPlayerChoice() << endl; //Shows player's choice
	cout << playerOne.getCompChoice() << endl; //Shows computer's choice
}