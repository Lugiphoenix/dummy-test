// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <iostream>

Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty()) throw WordContainsNoLetters{};
	convertCase();
	isThereSpace();
	removePunctuation();


	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	if (word_ == rhs.word_)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
    if ( word_.size() >= 3 )
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Word::convertCase()
{
    string tempWord = "";
    for ( unsigned int i = 0; i < word_.size(); i++ )
    {
        tempWord += tolower(word_.at(i));
    }
    word_ = tempWord;
}

void Word::isThereSpace()
{
    for ( unsigned int i = 0; i < word_.size(); i++ )
    {
        if (isspace(word_[i]))
        {
            throw WordContainsSpace();
        }
    }
}

void Word::removePunctuation()
{
    string tempWord = "";

    for ( unsigned int i = 0; i < word_.size(); i++ )
    {
        if (isalnum(word_[i]))
            {
                tempWord += word_[i];
            }
    }
    word_ = tempWord;

    if (word_.size() <= 0)
    {
        throw WordContainsNoLetters();
    }
}
