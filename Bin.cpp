/*Bin.cpp*/

/*********************************************
Bins of information.  Bins will be
indexed according to the data being stored.
Uses the Record class for entries.
Functions for adding, removing, and viewing
entries are included. Constructors and 
Destructors are also included.
Author: Samuel Patrick 9/7/16
*********************************************/
#include record.h
#include bin.h
#include <iostream>
using namespace std;

bin::bin(char indx)
{
	index = indx;
	num_entries = 0;
	next = NULL;  
	head = NULL; 
};

bin::~bin()
{
	record *tmp = head;  //temp pointer to traverse the records

	if (num_entries == 0  && next == NULL)
	{
		delete next;
		delete head;
	}
	else
	{
		//delete all the records in the bin
		while (num_entries > 1)
		{
			while (tmp->next->next != NULL)
				tmp = tmp->next;

			delete tmp->next;
			tmp->next = NULL;
			tmp = head;
			num_entries--;
		}
		delete head;
		delete next;
	}
};

void bin::add_entry(char& word)
{
	record *tmp = head;
	record *entry = new record(char& word);

	if (head == NULL)
		head = entry;
	else
	{
		//find the right place in the linked list to insert the new record
		while (tmp->next.size < entry.size && tmp->next != NULL)
			tmp = tmp->next;

		entry->next = tmp->next;
		tmp->next = entry;
	}
};

void bin::remove_entry(char& word)
{
	bool match = false;
	record *tmp, *prev = head;
	record *entry = new record(char& word);

	//Check for an empty bin
	if (head == NULL)
		match = false;
	else
	{
		//Find the first record of at least the same size
		while (tmp->next.size < entry.size)
		{
			prev = tmp;
			tmp = tmp->next;
		}

		//Check records of the same size for a match
		while (match == false && tmp.size == entry.size)
		{
			for (int i = 0; i < entry.size; i++)
			{
				if (entry[i] != tmp[i])
					break;
				else if (i == (entry.size - 1) && entry[i] == tmp[i])
					match = true;
			}

			if (match == false)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			else if (match == true)
			{
				prev->next = tmp->next;  //Make sure the list stays linked correctly
				delete tmp;
			}
		}
	}
	
	delete entry;
};

//Search the bin to see if a record is in it
bool bin::search(char& word)
{
	bool match = false;
	record *tmp = head;
	record *entry = new record(char& word);
	
	//Check if the bin has any records to check
	if (head == NULL)
		match = false;
	else
	{
		//Find the first record of at least the same size
		while (tmp->next.size < entry.size  && tmp->next != NULL)
			tmp = tmp->next;
		
		//Check for a matching record
		while (match == false && tmp.size == entry.size)
		{
			//Compare the records character by character
			for (int i = 0; i < entry.size; i++)
			{
				if (entry[i] != tmp[i])
					i = entry.size;
				else if (i == (entry.size - 1) && entry[i] == tmp[i])
					match = true;
			}

			//Go to next record if no match yet
			if (match == false)
			{
				tmp = tmp->next;
			}
		
		}
	}
	
	delete entry;

	return match;
};

void bin::print()
{
	record *tmp = head;

	while (tmp != NULL)
	{
		cout << tmp.word << "\t\t" << tmp.size << "\t\t" << tmp.bind << "\n";
		tmp = tmp->next;
	}
};
