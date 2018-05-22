// word.h
#ifndef WORD_H
#define WORD_H
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
	void print();
	
private:
	std::string m_word;
	int m_count;

};
#endif /* WORD_H */