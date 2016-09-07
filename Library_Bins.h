/* Library_Bins.h*/

/*******************************************************************************
Define a class for a library of bins.  Provides access to the member functions
in Library_Bins.cpp. The bins are a linked list, and share a common attribute
to identify the contents (e.g. words, numbers, etc.). Each bin contains a
linked list of entries which share the same index for that bin.
*******************************************************************************/
#ifndef LIBRARY_BINS_H
#define LIBRARY_BINS_H
#include bin.h

class bin_library{
	int bins;    //number of bins in the library
	bin *lBin;
	void add_bin();
	void remove_bin();
public:
	//constructor and destructor
	bin_library();
	~bin_library();
	
	bool search(char& data);
}
#endif
