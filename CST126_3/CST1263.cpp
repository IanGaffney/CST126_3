// CST1263.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <utility>
#include <string>
#include <sstream>
#include "word.h"

bool openFile(std::ifstream & inputFile);
int findWordArrayLocation(const std::string &word, Word * &wordArray, const int &arraySize);
void addWordToArray(const std::string &word, Word * &wordArray, const int &arraySize);
void sortDecending(Word* &wordArray, const int &arraySize);

int main()
{
	// open file
	std::ifstream file;
	Word* wordArray;

	// ask for the file name and open it
	openFile(file);

	std::cout << std::endl;

	// grab first line/word to get the total number of words
	int numOfWords{};
    // found here https://stackoverflow.com/questions/20372661/read-word-by-word-from-file-in-c
	// grabs next object separated by whitespace similar to cin >> var grabing everything until whitespace
	if (!(file >> numOfWords)) { // grab first "word", should be number of words in file
		std::cout << "file is empty" << std::endl;
		return -1;
	}
	wordArray = new Word[numOfWords];

	std::string word;
	while (file >> word)
	{
		// https://www.geeksforgeeks.org/removing-punctuations-given-string/
		// removes punctuation from string
		for (size_t i{}, len{ word.size() }; i < len; i++)
		{
			// check whether parsing character is punctuation or not
			if (ispunct(word[i]))
			{
				word.erase(i--, 1);
				len = word.size();
			}
		}
		// https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
		// convert word to lowercase
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		// add word to array and/or increment its count
		addWordToArray(word, wordArray, numOfWords);
	}

	// sort the array from highest to lowest count
	sortDecending(wordArray, numOfWords);

	// print out the words
	int counter{};
	while (wordArray[counter].getCount() != 0)
	{
		wordArray[counter].print();
		counter++;
	}

	std::cout << std::endl;

	delete[] wordArray;
    return 0;
}

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

void addWordToArray(const std::string &word, Word * &wordArray, const int &arraySize)
{
	int wordLocation{ findWordArrayLocation(word, wordArray, arraySize) };
	if (wordArray[wordLocation].getCount() == 0)
	{
		wordArray[wordLocation].setWord(word);
	}
	wordArray[wordLocation].incrementCount();
}

int findWordArrayLocation(const std::string &word, Word * &wordArray, const int &arraySize)
{
	int wordLocation{};
	while (wordArray[wordLocation].getWord() != word && wordArray[wordLocation].getCount() != 0 && wordLocation < arraySize)
	{
		wordLocation++;
	}
	return wordLocation;
}

// used candy.cpp example for sorting
void swapValues(Word& w1, Word& w2)
{
	Word temp = w1;
	w1 = w2;
	w2 = temp;
}

int indexOfLargest(Word* &wordArray, const int &startIndex, const int &arraySize)
{
	int max{ wordArray[startIndex].getCount() },
		indexOfMax{ startIndex };

	for (int index{ startIndex + 1 }; index < arraySize; index++)
		if (wordArray[index].getCount() > max)
		{
			max = wordArray[index].getCount();
			indexOfMax = index;
		}

	return indexOfMax;
}

void sortDecending(Word* &wordArray, const int &arraySize)
{
	int indexOfNextLargest{};

	for (int index{}; index < arraySize - 1; index++)
	{
		//Place the correct value in wordArray[index]:
		indexOfNextLargest = indexOfLargest(wordArray, index, arraySize);
		swapValues(wordArray[index], wordArray[indexOfNextLargest]);
	}
}