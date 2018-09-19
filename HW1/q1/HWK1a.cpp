/**
 * @file HWK1a.cpp
 * @author Yogesh Mundhra
 * @date   5/31/2018
 * @version 1.0
 *
 * @brief <ENSC 251, Homework 1a>
 *
 * @section This program allows a user to play rock, paper and scissors with computer
 *			The computer generates a random tool to play the game with
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
string convertChoice(int choice);
int main()
{
	Player user;
    int userchoice = 0;
    int compScore = 0;
    int playerScore = 0;
    char winner = '\0';
    char yeschar = '\0';
    string playername;
    string name = "\0";
	// Lets user enter their own name
    cout << "Please enter your name: ";
    getline(cin,playername);
    user.setPlayerName(playername);
	//The following do-while loop lets the user play again and again
	do
	{
		user.numGen();
		cout << "Please enter 1 for rock, 2 for paper and 3 for scissors: ";
		cin >> userchoice;
		user.setPlayerChoice(userchoice);
		winner = user.checkWinner();
		//This while loop verifies that if an error code e was returned
		//then the player must enter a valid choice again
		while(winner == 'e')
		{
			cout << "\nError: you did not enter a valid choice\n";
			cout << "Please enter 1 for rock, 2 for paper and 3 for scissors: ";
			cin.clear();
			cin >> userchoice;
			user.setPlayerChoice(userchoice);
			winner = user.checkWinner();
		}
		//This if statement relies on a p input from checkWinner()
		//Which means the player won
		if (winner == 'p')
		{
			// Adds 1 to the player score and shows the user what the computer chose
			playerScore++;
			cout << convertChoice(user.getPlayerChoice()) << " beats ";
			cout << convertChoice(user.getCompChoice()) << endl;
			cout << "You win!\n";
			cout << "Your score is " << user.getPlayerName() << " " << playerScore;
			cout << ":" << compScore << " " << "Computer";
		}
		else if (winner == 'c')
		{
			// Adds 1 to the computer score and shows the user what the computer chose
			compScore++;
			cout << convertChoice(user.getCompChoice()) << " beats ";
			cout << convertChoice(user.getPlayerChoice()) <<endl;
			cout << "You lose!\n";
			cout << "The score is " << user.getPlayerName() << " " << playerScore;
			cout << ":" << compScore << " " << "Computer";
		}
		else if (winner == 'd')
		{
			// Shows the user what the computer chose
			cout << "You both chose " << convertChoice(user.getPlayerChoice())<<endl;
			cout << "It's a draw!\n";
			cout << "The score is " << user.getPlayerName() << " " << playerScore;
			cout << ":" << compScore << " " << "Computer";
		}
		cout << "\nDo you want to play again? (y/n): ";
		cin >> yeschar;
	}
	while(yeschar == 'y' || yeschar == 'Y');
	//Reveals final score
	cout << "The final score is " << user.getPlayerName() << " " << playerScore;
	cout << ":" << compScore << " " << "Computer" << endl;
	return 0;
}
/**
* @brief Generates random number between 1 to 3 using the ctime library
*		 and sets it as the computer choice;
* @param null
* @return void
*/
void Player::numGen()
{
        int tempChoice = 0;
        srand(time(NULL));
        tempChoice = (rand() % 3) + 1;
        setComputerChoice(tempChoice);
}
/**
* @brief Checks for all combinations to determine winner and returns
*		 first character for result
*		 p means player, c means computer, d means draw and e is for error
* @param null
* @return char
*/
char Player::checkWinner()
{
    const char playerwin = 'p';
    const char compwin = 'c';
    const char draw = 'd';
    const char error = 'e';
    const int rock = 1;
    const int paper = 2;
    const int scissors = 3;
    if(getPlayerChoice() == rock)
    {
        if(getCompChoice() == rock)
        {
            return draw;
        }
        else if(getCompChoice() == paper)
        {
            return compwin;
        }
        else if(getCompChoice() == scissors)
        {
            return playerwin;
        }
    }
    else if(getPlayerChoice() == paper)
    {
        if(getCompChoice() == rock)
        {
            return playerwin;
        }
        else if(getCompChoice() == paper)
        {
            return draw;
        }
        else if(getCompChoice() == scissors)
        {
            return compwin;
        }
    }
    else if(getPlayerChoice() == scissors)
    {
        if(getCompChoice() == rock)
        {
            return compwin;
        }
        else if(getCompChoice() == paper)
        {
            return playerwin;
        }
        else if(getCompChoice() == scissors)
        {
            return draw;
        }
    }
    else
    {
    return error;
    }
}
/**
* @brief Converts 1,2,3 back to rock, paper or scissor. Used to tell 
*        user what the computer chose.
* @param choice, the integer between 1 to 3 of the weapon
* @return string
*/
string convertChoice(int choice)
{
    if (choice == 1)
    {
    return "rock";
    }
    else if(choice == 2)
    {
    return "paper";
    }
    else if(choice == 3)
    {
    return "scissors";
    }
}