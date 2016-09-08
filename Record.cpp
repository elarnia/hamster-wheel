/*Record.cpp*/

/********************************
Creates a record from data, and
identifies it size.  Currently
written for words, but any data
could be stored.
Author: Samuel Patrick 9/7/16
********************************/
#include record.h

//Constructor
record::record(char& data)
{
	word = &data;
	size = 0;
	next = NULL;

	for (int i = 0; word[i] != '\0'; i++)
	{
		size++;
	}

	bind_word();
};

//Destructor
record::~record()
{
	delete word;
	delete next;
};


//Compute a 'bind' value based on letters in the word.
void record::bind_word()
{
	int first, second, third;

	//Get values from the data, and check they are valid
	if (word[0] != '\0' && size > 0)
		first = word[0];
	else
		first = 0;
	
	if (word[1] != '\0' && size > 1)
		second = word[0];
	else
		second = 0;
	
	if (word[2] != '\0' && size > 2)
		third = word[0];
	else
		third = 0;
	
	bind = first * (second + third);
};

//Return the size of the record
int record::getSize()
{
	return size;
};

//Return the bind of the record
int record::getBind()
{
	return bind;
};

//Return the record
const char& record::getWord()
{
	return word;
};
