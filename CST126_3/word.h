// word.h
#include "stdafx.h"
#include <string>

class Word {
public:
	Word();
	Word(std::string word);
	std::string getWord() { return m_word; }
	int getCount() { return m_count; }
	void setWord(std::string word) { m_word = word; }
	void incrementCount() { m_count++; }
	
private:
	std::string m_word;
	int m_count;

};