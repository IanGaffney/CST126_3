// CST1263.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "word.h"

bool openFile(std::ifstream & inputFile);

int main()
{
	// open file
	std::ifstream file;
	Word* wordHead;

	openFile(file);



	// grab first line/word to get the total number of words

	// loop through words
		// change to lower case
		// remove punctuation
		// if word is in my list of words, increment number for that word
		// else create new word instance, and set to 1

	// output words in order of frequency 


	
    return 0;
}

//--------------------------------------------------------------------
// Functions
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// bool    openFile(file)
// Input:  file name (retrieved from user);
// Output: file pointer. 
//         Returns true if able to open file and false if 
//           unable to open file
//  Hint:  we've had hands on that did this.
//  From CST126_2
bool openFile(std::ifstream & inputFile)
{
	std::string filename{};
	std::cout << "Please enter the input file name including extension : " << std::flush;
	std::cin >> filename;

	inputFile = std::ifstream(filename);

	if (inputFile.fail())
	{
		std::cout << "ERROR - Could not open file!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}