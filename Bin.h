/*Bin.h*/

/*************************************
Define the bin class and provide
access to member functions in Bin.cpp.
Creates bins for information to be
sorted into. Bins are linked lists,
and the entries in a bin are linked
lists.
Author: Samuel Patrick 9/7/16
**************************************/

#ifndef INCLUDE_BIN_H
#define INCLUDE_BIN_H
#include "record.h"

class bin {
	char _index;  // The indentifier for the bin
	int _num_entries;  // How many records in this bin
	bin *_next;  //points to the next bin.
	record *_head;

public:
	//Contructor and destructor for the bin
	bin(char index);
	~bin();

	void add_entry(char& word); //Allows access to Record.h record()
	void remove_entry(char& word); //Allows access to Record.h ~record()
	bool search(char& word);  //see if a record is in the bin
	void print();  //show all the records in the bin
	char get_index(); //Returns index
	int get_size(); //Returns num_enries
	void get_next(bin *next); //Allows access to bin->next
	void get_entries(record *head);  //Allows access to bin->head 
};
#endif
