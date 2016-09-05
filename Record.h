/*Record.h*/

/*******************************************
Define Class Record and proivde access to 
member functions in Record.cpp.  Allows data
to be stored as an object with attributes.
Entries are stored via a linked list.
*******************************************/

#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

class record{
	int size;
	int bind; //Value computed from letters in the word
	char* word;
	record *next;  // points to the next record
	void bind_word();
public:
	//Constructors & Destructor
	record(char& data);
	~record();

	//Access functions
	int getSize();
	int getBind();
	const char& getRecord();
};

#endif