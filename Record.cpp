/*Record.cpp*/

/********************************
Creates a record from data, and
identifies it size.  Currently
written for words, but any data
could be stored. Also includes
********************************/
#include record.h

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

int record::getSize()
{
	return size;
};

int record::getBind()
{
	return bind;
};

const char& record::getWord()
{
	return word;
};