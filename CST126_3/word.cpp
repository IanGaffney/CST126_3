// word.cpp
#include "stdafx.h"
#include "word.h"
#include <string>

Word::Word() :
	m_word(""), m_count(0)
{
}

Word::Word(std::string word) :
	m_word(word), m_count(1)
{
}
