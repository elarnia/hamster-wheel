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
#include "record.h"
#include "bin.h"
#include <iostream>
using namespace std;

bin::bin(char index)
{
	_index = index;
	_num_entries = 0;
	_next = 0;  
	_head = 0; 
};

bin::~bin()
{
	record *tmp = _head;  //temp pointer to traverse the records

	if (_num_entries == 0  && _next == 0)
	{
		delete _next;
		delete _head;
	}
	else
	{
		//delete all the records in the bin
		while (_num_entries > 1)
		{
			while ((tmp->_next)->_next != 0)
				tmp = tmp->_next;

			delete tmp->_next;
			tmp->_next = 0;
			tmp = _head;
			_num_entries--;
		}
		delete _head;
		delete _next;
	}
};

void bin::add_entry(char& word)
{
	record *tmp = _head;
	record *entry = new record(&word);
	int esize = entry->get_size();

	if (_head == 0)
		_head = entry;
	else
	{
		//find the right place in the linked list to insert the new record
		while ((tmp->_next)->get_size() < esize && tmp->_next != 0)
			tmp = tmp->next;

		entry->_next = tmp->_next;
		tmp->_next = entry;
	}
};

void bin::remove_entry(char& word)
{
	bool match = false;
	record *tmp, *prev = _head;
	record *entry = new record(&word);
	int esize = entry->get_size(); //Reduce function calls

	//Check for an empty bin
	if (head == 0)
		match = false;
	else
	{
		//Find the first record of at least the same size
		while ((tmp->_next)->get_size() < esize)
		{
			prev = tmp;
			tmp = tmp->_next;
		}

		//Check records of the same size for a match
		while (match == false && tmp->get_size() == esize)
		{
			for (int i = 0; i < esize; i++)
			{
				if (*entry[i] != *tmp[i])
					i = esize;
				else if (i == (esize - 1) && *entry[i] == *tmp[i])
					match = true;
			}

			if (match == false)
			{
				prev = tmp;
				tmp = tmp->_next;
			}
			else if (match == true)
			{
				prev->_next = tmp->_next;  //Make sure the list stays linked correctly
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
	record *tmp = _head;
	record *entry = new record(word);
	int esize = entry->get_size();
	
	//Check if the bin has any records to check
	if (_head == 0)
		match = false;
	else
	{
		//Find the first record of at least the same size
		while ((tmp->_next)->get_size() < esize  && tmp->_next != 0)
			tmp->get_next(tmp);
		
		//Check for a matching record
		while (match == false && tmp->get_size() == esize)
		{
			//Compare the records character by character
			for (int i = 0; i < esize; i++)
			{
				if (*entry[i] != *tmp[i])
					i = esize;
				else if (i == (esize - 1) && *entry[i] == *tmp[i])
					match = true;
			}

			//Go to next record if no match yet
			if (match == false)
			{
				tmp->get_next(tmp);
			}
		
		}
	}
	
	delete entry;

	return match;
};

void bin::print()
{
	record *tmp = _head;
	char *word = tmp->get_record(word);

	while (tmp != 0)
	{
		cout << word << "\t\t" << tmp->get_size() << "\t\t" << tmp->get_bind() << "\n";
		tmp->get_next(tmp);
	}
};


char bin::get_index()
{
	return _index;
};

int get_size()
{
	return _num_entries;
};

//Points the user to next bin in the library
void get_next(bin &next)
{
	next = _next;
};

//Points the user to the head of the bins records
void get_entries(record &ptr)
{
	ptr = _head;
};
