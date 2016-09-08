/* Library_Bins.h*/

/*******************************************************************************
Define a class for a library of bins.  Provides access to the member functions
in Library_Bins.cpp. The bins are a linked list, and share a common attribute
to identify the contents (e.g. words, numbers, etc.). Each bin contains a
linked list of entries which share the same index for that bin.
Author: Samuel Patrick 9/7/16
*******************************************************************************/
#ifndef LIBRARY_BINS_H
#define LIBRARY_BINS_H
#include "bin.h"

class bin_library{
	int bins;    //number of bins in the library
	bin *top;  //head of the bin linked list
	
public:
	//constructor
	bin_library();
	//destructor
	~bin_library();
	
	bool search(char& data);  //Check if data is in the library
	void print_library();  //Print the contents of the library
	void add_entry(char& word);  //Add an entry to the library
	void add_bin(char index); //Add a new bin with the index given
	void remove_bin(bin *target); //Delete the target
	int get_bins(); //Return the number of bins in the library
	void list_bins();  //Print the index of all the bins
}
#endif
