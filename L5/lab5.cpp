/**
* @file Lab5.cpp
* @author Yogesh Mundhra
* @Date 22th June 2018
* @version 1.0
* @section This program is supposed to play the letter game Ladder
*		   given two words and a dictionary file.
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Yogesh Mundhra ____ _____22th June 2018______________
//
// ____ 301346798 ______
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
bool validWord(string string1, int length);
bool sameLength(string string1, string string2);
string ladder(string begin, string target, int length);
//I am aware the program is not complete but I found this lab very challenging
//and have tried my best. Theoretically, my function should work however 
//there are frequent stack overflows.
//This vector is where the dictionary is stored for quicker access
vector <string> dictionary;
int lengthCounter=0;
int main()
{
	string filename = "\0";
	ifstream inFile;
	string beginWord = "\0";
	string endWord = "\0";
	string temp = "\0";
	string temp2 = "\0";
	string ladResult = "\0";
	bool validFlag = false;
	bool validFlag2 = false;
	bool lengthFlag = false;
	string* subDict = NULL;
	int length = 0;
	cout << "Welcome to Ladder.\n";
	//The following do-while loop runs until the file is properly opened.
	do
	{
		cout << "Enter a file name: ";
		cin >> filename;
		inFile.open(filename.c_str());
	}
	while(!(inFile.is_open()));
	//The following for loop puts all words into the dictionary vector.
	for(int i = 0; i < 87314; i++)
	{
		inFile >> temp;
		dictionary.push_back(temp);
	}
	//The following nested do while loops run until the words are 
	//valid and until they are the same length
	do
	{
		do
		{
			cout << "Please enter a word to begin with: ";
			cin >> beginWord;
			validFlag = validWord(beginWord, beginWord.length());
			if(validFlag)
			{
				break;
			}
			//prompts user to input word again if word is not correct
			else if(!validFlag)
			{
				cout << "Invalid word, please enter a word in the dictionary.\n";
			}
		}
		while(!validFlag);
		do
		{
			cout << "Please enter a word to end with: ";
			cin >> endWord;
			validFlag2 = validWord(endWord, endWord.length());
			if(validFlag2)
			{
				break;
			}
			else if(!validFlag2)
			{
				cout << "Invalid word, please enter a word in the dictionary.\n";
			}
		}
		while(!validFlag2);
		//The following assignment checks for the correct length
		lengthFlag = sameLength(beginWord, endWord);
		if(lengthFlag)
		{
			break;
		}
		else if(!lengthFlag)
		{
			cout << "Words are not the same length.\n"
				 << "Please try again.\n";
		}
	}
	while(!lengthFlag);
	//The following for loop converts both words to lowercase
	for(unsigned int j = 0; j <= beginWord.length(); j++)
	{
			beginWord[j] = tolower(beginWord[j]);
			endWord[j] = tolower(endWord[j]);
	} 
	//This assignment stores the length of the words as integers
	length = beginWord.length();
	//The following for loop counts how many words of the length
	//of the words typed in are.
	for(int k = 0; k < dictionary.size(); k++)
	{
		if(dictionary[k].length() != length)
		{
			continue;
        }
		else
		{
			lengthCounter++;
		}
	}
	//This creates a new dynamic array of strings
	subDict = new string [lengthCounter];
	//All the words of the same length are put in a subdictionary
	//by the help of this fot loop
	for(int kk = 0; kk < dictionary.size(); kk++)
	{
		if(dictionary[kk].length() != length)
		{
			continue;
        }
		else
		{
		for(int ik=0; ik<lengthCounter; ik++)
			{	
				subDict[ik] = dictionary[kk];
				break;
			}
		}
	}
	//This calls the ladder function to work
	cout << ladder(beginWord, endWord, length);
	return 0;
}
/**
* @brief Verifies if the words entered are valid or not
* @section converts word to lowercase and compares to ASCII values
*		   for 'a' to 'z'
*		   then checks if the word exists in the dictionary
* @param string string1 this is the string passed
* @param int length this is the length of the word
* @return bool
*/
bool validWord(string string1, int length)
{
	for(unsigned int i = 0; i < string1.size(); i++)
	{
		int lowerChar = tolower(string1[i]);
		if(lowerChar < 'a' || lowerChar > 'z')
		{
			cin.clear();
			cin.ignore(1000,'\n'); 
			return false;
		}
	}
	for(unsigned int j = 0; j < dictionary.size(); j++)
	{
		if(dictionary[j] != string1)
		{
			continue;
		}
		else if(dictionary[j] == string1)
		{
			return true;
		}
	}
	return false;
}
/**
* @brief Verifies if the words entered are the same length
* @param string string1 this is the first string passed
* @param string string2 this is the second string passed
* @return bool
*/
bool sameLength(string string1, string string2)
{
	if(string1.size() == string2.size())
	{
		return true;
	}
	else if(string1.size() != string2.size())
	{
		return false;
	}
}
/**
* @brief This is a recursive function that does the job
*		 of looking for the right words to create
*		 a ladder. It is essentially meant to replicate
*		 a breadth-first search.
* @param string begin this is the starting point of the ladder
* @param string target this is the final word to be reached.
* @return string
*/
string ladder(string begin, string target, int length)
{
	bool validChange = false;
	string tempBeg = begin;
	string fin="\0";
	//If the beginning word is the target word then the ladder is complete.
	//This is also the BASE CASE for the recursive function.
	if(tempBeg == target)
	{
		return tempBeg;
	}
	//do
	//{
	//This for loop iterates for all the letters in the word.
	for(int ii=0; tempBeg!=target; ii++)
	{
		for(unsigned int i = 0; i < length; i++)
		{
		//If the letter required in the final word is already existing
		//It goes through one more iteration
			if(tempBeg[i] == target[i])
			{
				continue;
			}
		//This for loop tests for all characters a to z and whether they make
		// a real word. It does so by changing the characters and using their 
		//ASCII codes
			for(int jj = 97; jj <= 122; jj++)
			{
				//if the for loop character is already the character, then it continues;
				if(tempBeg[i]==jj)
				{
					continue;
				}
				else
				{
					//set value to ascii character
					tempBeg[i] = jj;
					//checks for validity of word
					//on a newer edition of the program, this would only 
					//check the subdictionary I created.
					validChange = validWord(tempBeg, length);
					if(validChange)
					{
						//If the word isn't the starting word
						//it is printed out
						if(tempBeg != begin)
						{
							cout << tempBeg << endl;
							//recursively calls the ladder function to check for other words.
							while(fin!=target)
							{
								fin = ladder(tempBeg, target, length);
							}
							break;
						}
					}
					else
					{
						continue;
					}
					break;
				}
			}
	//}
	//while(tempBeg!=target);

		}
		break;
	}
	return fin;
}
// STUBS
// For reference or changes in implementation
// string dictionary[87314]={"\0"};
// string* subDict;
// bool validInSpecific(string string1, string *dict, int lengthC);
/*bool validInSpecific (string string1, string *dict, int lengthC)
{
	for(unsigned int j=0; j<lengthC; j++)
	{
		if(dict[j]!=string1)
		{
			continue;
		}
		else if(dict[j]==string1)
		{
			return true;
		}
	}
	return false;
}
/*		
{
		for(unsigned int j=0; j<length; j++)
		{
			if(begin[i]!=target[j])
			{
				for(int jj=97; jj<=122; jj++)
				{
					asciiChar=jj;
						tempBeg[i]=jj;
						validChange=validWord(tempBeg);
						if(validChange && tempBeg[i]==target[j])
						{
							return tempBeg;
						}
						else
						{
							break;
						}
					continue;
				}
			}
			else
			{
				break;
			}
		}
		continue;
	}
	*/
/*for(int k=0; k<87314; k++)
	{
		if(dictionary[k].length() !=length)
		{
			continue;
        }
		else
		{
			lengthCounter++;
		}
	}
	subDict = new string[lengthCounter];
	for(int kk=0; kk<87314; kk++)
	{
		if(dictionary[kk].length() !=length)
		{
			continue;
        }
		else
		{
		for(int ik=0; ik<lengthCounter; ik++)
			{	
				subDict[ik]=dictionary[kk];
				break;
			}
		}
	} */
