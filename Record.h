/*Record.h*/

/*******************************************
Define Class Record and proivde access to 
member functions in Record.cpp.  Allows data
to be stored as an object with attributes.
Entries are stored via a linked list.
Author: Samuel Patrick 9/7/16
*******************************************/

#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

class record{
	int _size;
	int _bind; //Value computed from letters in the word
	char *_word;
	record *_next;  // points to the next record
	void bind_word();
public:
	//Constructors & Destructor
	record(char& word);
	~record();

	//Access functions
	int get_Size(); //Returns size
	int get_Bind(); //Returns bind
	void get_Record(char &word); //Copies the contents of _word into word
	void get_next(record *next); //Allows access to record->next
};

#endif
