/*Bin.cpp*/

/*********************************************
Bins of information.  Bins will be
indexed according to the data being stored.
Uses the Record class for entries.
Functions for adding, removing, and viewing
entries are included. Constructors and 
Destructors are also included.
*********************************************/
#include record.h
#include bin.h
#include <iostream>
using namespace std;

bin::bin(int indx)
{
	index = indx;
	num_entries = 0;
	next = NULL;  
	first = NULL; 
};

bin::~bin()
{
	record *tmp = first;  //temp pointer to traverse the records

	if (num_entries == 0  && next == NULL)
	{
		delete next;
		delete first;
	}
	else
	{
		//delete all the records in the bin
		while (num_entries > 0)
		{
			while (tmp->next != NULL)
				tmp = next;

			delete tmp;
			tmp = first;
			num_entries--;
		}
		delete next;
	}
};

void bin::add_entry(char& word)
{
	record *tmp = first;
	record *entry = new record(char &word);

	if (first == NULL)
		first = entry;
	else
	{
		//find the right place in the linked list to insert the new record
		while (tmp->next.size < entry.size)
			tmp = tmp->next;

		entry->next = tmp->next;
		tmp->next = entry;
	}
};

void bin::remove_entry(char& word)
{
	bool match = false;
	record *tmp, *prev = first;
	record *entry = new record(char& word);

	if (first == NULL)
		delete entry;
	else
	{
		while (tmp->next.size < entry.size)
		{
			prev = tmp;
			tmp = tmp->next;
		}

		do{
			for (int i = 0; i < entry.size; i++)
			{
				if (entry[i] != tmp[i])
					break;
				else if (i == (entry.size - 1) && entry[i] == tmp[i])
					match = true;
			}

			if (match == false && tmp->next.size == entry.size)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			else if (match == true)
			{
				prev->next = tmp->next;
				delete tmp;
			}
		} while (match == false && tmp.size == entry.size);
	}
};

bool bin::search(char& word)
{
	bool match = false;
	record *tmp, *prev = first;
	record *entry = new record(char& word);

	if (first == NULL)
		delete entry;
	else
	{
		while (tmp->next.size < entry.size)
		{
			prev = tmp;
			tmp = tmp->next;
		}

		do{
			for (int i = 0; i < entry.size; i++)
			{
				if (entry[i] != tmp[i])
					break;
				else if (i == (entry.size - 1) && entry[i] == tmp[i])
					match = true;
			}

			if (match == false && tmp->next.size == entry.size)
			{
				prev = tmp;
				tmp = tmp->next;
			}
		
		} while (match == false && tmp.size == entry.size);
	}
	
	delete entry;

	return match;
};

void bin::print()
{
	record *tmp = first;

	while (tmp != NULL)
	{
		cout << tmp.word << "\t\t" << tmp.size << "\t\t" << tmp.bind << "\n";
		tmp = tmp->next;
	}
};