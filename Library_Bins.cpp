/* Library_Bins.cpp*/

/*******************************************************************************
A library of bins that contain data.  Bins are created based off of a set index.
The index is an attribute of the entries stored in the library.  Entries will be
sorted in the bin by length.
*******************************************************************************/
#include bin.h

//Constructor
bin_library::bin_library()
{
	bins = 0;
	lBin = NULL;
};

//Destructor
bin_library::~bin_library()
{
	bin *temp=lBin;
	
	while(bins>1)
	{
		//Find the last bin in the list
		while(temp->next->next != null)
			temp = temp->next;
		
		remove_bin(temp->next);  //Delete the last bin in the list
		temp->next= NULL;  //Set the new tail of the list
		bins--;
		temp = lBin;
	}
	delete lBin;
};

//Create a new bin in the Library
void bin_library::add_bin(char index)
{
	bin *temp = lBin;
	
	if (bins == 0)
		lBin = new bin;
	else
	{	//Find the tail of the list
		while(temp->next != NULL)
			temp = temp->next;
	}
	
	temp->next = new bin(char index);  //Add the new bin to the end of the list
	temp->next->next = NULL;  //Set the new tail of the list
	bins++;
};

//Remove a bin from the Library
void bin_library::remove_bin(bin *target)
{
	delete target;
}
