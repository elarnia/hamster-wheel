/*Bin.h*/

/*************************************
Define the bin class and provide
access to member functions in Bin.cpp.
Creates bins for information to be
sorted into. Bins are linked lists,
and the entries in a bin are linked
lists.
**************************************/

#ifndef INCLUDE_BIN_H
#define INCLUDE_BIN_H
#include record.h

class bin {
	int index;  // The indentifier for the bin
	int num_entries;  // How many records in this bin
	bin *next;  //points to the next bin.
	record *first;

public:
	//Contructor and destructor for the bin
	bin(int indx);
	~bin();

	void add_entry(char& word);
	void remove_entry(char& word);
	bool search(char& word);  //see if a record is in the bin
	void print();  //show all the records in the bin
};
#endif