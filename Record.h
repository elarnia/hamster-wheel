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
	int size;
	int bind; //Value computed from letters in the word
	char *word;
	record *next;  // points to the next record
	void bind_word();
public:
	//Constructors & Destructor
	record(char& data);
	~record();

	//Access functions
	int get_Size(); //Returns size
	int get_Bind(); //Returns bind
	void get_Record(char *ptr); //Copies the contents of word into ptr
	void get_next(record *ptr); //Allows access to record->next
};

#endif
