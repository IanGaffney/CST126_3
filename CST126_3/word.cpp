// word.cpp
#include "stdafx.h"
#include "word.h"
#include <iostream>
#include <iomanip>
#include <string>

Word::Word() :
	m_word(""), m_count(0)
{
}

Word::Word(std::string word) :
	m_word(word), m_count(1)
{
}

void Word::print()
{
	std::cout << std::right << std::setw(16) << m_word << " " << std::left << std::setw(3) << m_count << std::endl;
}