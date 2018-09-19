/**
 * @file HWK1b.cpp
 * @author Yogesh Mundhra
 * @date   5/31/2018
 * @version 1.0
 *
 * @brief <ENSC 251, Homework 1>
 *
 * @section This program allows users to enter ratings for a movie and calculates the average for it
 *
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
#include <string>
using namespace std;
class Movie
{
    private:
        string movieName;
        string mpaa;
        int terrible;
        int bad;
        int ok;
        int good;
        int great;
        double numRatings;
        double average;

    public:
        // Constructors
        Movie()
        {
			//Default case initializes all variables and strings
            movieName = "Unnamed";
            mpaa = "Unrated";
            terrible = 0;
            bad = 0;
            ok = 0;
            good = 0;
            great = 0;
            average = 0.00;
            numRatings = 0.00;
        }
        Movie(string name, string MPAArating)
        {
			//Case with two arguments given to constructor;
            movieName = name;
            mpaa = MPAArating;
            terrible = 0;
            bad = 0;
            ok = 0;
            good = 0;
            great = 0;
            average = 0.00;
            numRatings = 0.00;
        }
        //Mutators
        void setName(string name)
        {
            movieName = name;
        }
        void setMPAA(string MPAArating)
        {
            mpaa = MPAArating;
        }
        //Accesssors
        string getName()
        {
            return movieName;
        }
        string getMPAA()
        {
            return mpaa;
        }
        void addRating(int rating);
        double getAverage();
        void showOutput(Movie &Film)
        {
            cout << "Movie Name: " << Film.getName() <<endl;
            cout << "MPAA Rating: " << Film.getMPAA() << endl;
            cout << "Average Rating: " << Film.getAverage() << endl;
        }
    };

    int main()
    {
		string name;
		string rating;
		char yesChar='n';
		int rate=0;
		//Test Driver function with 2 preset movies.
        Movie One("The Incredible Hulk", "PG13"); 
        Movie Two("The Room", "R");
        One.addRating(5);
        One.addRating(4);
        One.addRating(3);
        One.addRating(5);
        One.addRating(4);
        One.showOutput(One);

        Two.addRating(3);
        Two.addRating(2);
        Two.addRating(2);
        Two.addRating(3);
        Two.addRating(1);
        Two.showOutput(Two);
		// This part allows the user to input two movies now.
		cout << "Enter a movie name: ";
		getline(cin,name);
		cout << "Enter the MPAA rating: ";
		getline(cin,rating);
		//creates a new object User for the user entered movie and rating
		Movie User(name, rating);
		//This do while loop allows users to enter the ratings 
		//for the movies they have entered
		do
		{
			cout << "Enter a rating (1-5) for the movie: ";
			cin >> rate;
			User.addRating(rate);
			cout << "Would you like to add another rating? (y,n): ";
			cin >> yesChar;
		}
		while(yesChar == 'y' || yesChar == 'Y');
		User.showOutput(User);
        return 0;
}
/**
* @brief checks for rating to be within range and increments 
* rating by 1 depending on quality
* @param rating is the rating input by the user
* @return void
*/
void Movie::addRating(int rating)
	{
        if (rating>5 || rating<1)
        {
        cout << "A non-integer was entered for rating, please enter a number between 1 and 5\n";
        }
        else
        {
            if(rating == 1)
            {
            terrible++;
            }
            else if (rating == 2)
            {
            bad++;
            }
            else if (rating == 3)
            {
            ok++;
            }
            else if (rating == 4)
            {
            good++;
            }
            else if (rating == 5)
            {
            great++;
            }
            numRatings++;
        }
    }
/**
* @brief Calculates the average rating of the movie depending on the number of ratings
* @param N/A
* @return double
*/
double Movie::getAverage()
	{
		average = (terrible*1 + bad*2 + ok*3 + good*4 + great*5) / numRatings; 
		return average;
	}
