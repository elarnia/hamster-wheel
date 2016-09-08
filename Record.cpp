/*Record.cpp*/

/********************************
Creates a record from data, and
identifies it size.  Currently
written for words, but any data
could be stored.
Author: Samuel Patrick 9/7/16
********************************/
#include "record.h"

//Constructor
record::record(char& word)
{
	_word = *word;
	_size = 0;
	_next = 0;

	for (int i = 0; _word[i] != '\0'; i++)
	{
		_size++;
	}

	bind_word();
};

//Destructor
record::~record()
{
	delete _word;
	delete _next;
};


//Compute a 'bind' value based on letters in the word.
void record::bind_word()
{
	int first, second, third;

	//Get values from the data, and check they are valid
	if (_word[0] != '\0' && size > 0)
		first = _word[0];
	else
		first = 0;
	
	if (_word[1] != '\0' && size > 1)
		second = _word[0];
	else
		second = 0;
	
	if (_word[2] != '\0' && size > 2)
		third = _word[0];
	else
		third = 0;
	
	bind = first * (second + third);
};

//Return the size of the record
int record::get_Size()
{
	return _size;
};

//Return the bind of the record
int record::get_Bind()
{
	return _bind;
};

//Copies the contents of word into ptr
void record::get_record(char &word)
{
	*word = *_word;
};

//Sets ptr to next 
void record::get_next(record *ptr)
{
	ptr = _next;
};
