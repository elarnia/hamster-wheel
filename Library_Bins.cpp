/* Library_Bins.cpp*/

/*******************************************************************************
A library of bins that contain data.  Bins are created based off of a set index.
The index is an attribute of the entries stored in the library.  Entries will be
sorted in the bin by length.
*******************************************************************************/
#include bin.h

class bin_library{
	int bins;    //number of bins in the library
	void add_bin();
	void remove_bin();
public:
	//constructor and destructor
	bin_library();
	~bin_library();

}