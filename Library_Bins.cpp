/* Library_Bins.cpp*/

/*******************************************************************************
A library of bins that contain data.  Bins are created based off of a set index.
The index is an attribute of the entries stored in the library.  Entries will be
sorted in the bin by length.
Author: Samuel Patrick 9/7/16
*******************************************************************************/
#include "bin.h"
#include <iostream>
using namespace std;

//Constructor
bin_library::bin_library()
{
	bins = 0;
	top = 0;
};

//Destructor
bin_library::~bin_library()
{
	bin *temp, *prev = top;
	
	while(bins>1)
	{
		//Find the last bin in the list
		while(temp->next != 0)
		{
			prev = temp;
			temp.get_next(temp);
		}
		
		remove_bin(temp);  //Delete the last bin in the list
		prev->next = 0;  //Set the new tail of the list
		bins--;
		prev = temp = top;
	}
	
	delete top;
};

//Create a new bin in the Library
void bin_library::add_bin(char index)
{
	bin *temp = top;
	
	if (bins == 0)
		temp = top;
	else
	{	//Find the tail of the list
		while(temp != 0)
			temp.get_next(temp);
	}
	
	temp = new bin(index);  //Add the new bin to the end of the list
	bins++;
};

//Remove a bin from the Library
void bin_library::remove_bin(bin *target)
{
	delete target;
};

bool bin_library::search(char& word)
{
	bool match = false;
	bin *tmp = top;
	
	//Check if the bin has any records
	if (tmp == 0)
		match = false;
	else
	{
		//Find the bin with a matching index
		while(tmp != 0 && match == false)
		{
			//Check the index for lower and upper case
			if (tmp.index == word[0] || (tmp.index + 32) == word[0])
				match == true;
			else
				tmp.get_next(tmp);
		}
		
		//If a bin with a matching index was found, search it for the record
		if(match == true)
			match = tmp.search(word);
	}
	
	return match;
};

void bin_library::add_entry(char& word)
{
	bin *temp = top;
	char index = word[0];

	//finding a matching bin for the word
	while (temp != 0)
	{
		if (temp.index == index)
		{
			temp.add_entry(word);
			temp = 0;
		}
		else
			temp.get_next(temp);
	}

};

//Print all the records in the library
void bin_library::print_library()
{
	bin *tmp = top;
	
	//Print a header
	cout << "~~~~~~~~~~~~~~~~~~Library~~~~~~~~~~~~~~~~~\n";
	
	//Print each bin
	for(int i = bins; i>0; i--)
	{
		tmp.print();
		cout << "***\t\t***\t\t***\t\t***\n";
		tmp.get_next(tmp);
	}
	
};

//Return the number of bins in the library
int get_bins()
{
	return bins;
};

//Print the index of all the bins
void list_bins()
{
	bin *tmp = top;
	while(tmp != 0)
	{
		cout << tmp.get_index() << endl;
		tmp.get_next(tmp);  //tmp = tmp->next
	}
};
