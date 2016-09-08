/*Main.cpp*/

/*******************************************
A driver for the Library Bin implementation.
Creates a linked list of linked lists, and 
manipulates the data in them.
Author: Samuel Patrick 9/7/16
********************************************/
#include "library_bins.h"
#include <iostream>
using namespace std;

void main()
{
	//a variable for user input
	char user[5] = { '\0' };
	int menu = 0;
	//words to add to the libary
	char t1[] = "cow";
	char t2[] = "who";
	char t3[] = "why";
	char t4[] = "car";
	char t5[] = "cake";
	char t6[] = "whisk";
	char t7[] = "apple";
	char t8[] = "banana";
	char t9[] = "carrot";
	char t10[] = "desk";
	char t11[] = "elephant";
	char t12[] = "field";
	char t13[] = "giraffe";
	char t14[] = "hotel";
	char t15[] = "india";
	char t16[] = "lime";
	char t17[] = "joker";
	char t18[] = "kiwi";
	char t19[] = "mango";
	char t20[] = "nectarine";
	char t21[] = "orange";
	char t22[] = "pineapple";

	//create the library
	bin_library *me = new bin_library;

	//create the bins for the library
	for (char y = 'a'; y <= 'z'; y++)
		me.add_bin(y);
	//add the predefined words to the library
	me.add_entry(t1);
	me.add_entry(t2);

	//create menu for user input
	while (menu != 7)
	{
		cout << "\fWelcome to the Library\n";
		cout << "select one of the following options\n";
		cout << "1. Search for Entry\n";
		cout << "2. Delete Entry\n";
		cout << "3. Print by index\n";
		cout << "4. Print Library\n";
		cout << "5. Delete by index\n";
		cout << "6. Delete Library\n";
		cout << "7. Exit Library\n";
		cout << ":  ";

		cin >> menu;

		if (menu == 1)
		{
			cout << "Please enter the word to search for:\n";

			//Get user input
			for (int i = 0; i < 4; i++)
				cin.get(user[i]);

			//Print result
			cout << "Search result is " << me.search(user) << endl;
			
		}
		else if (menu == 2)
		{
			cout << "Please enter the entry to delete:  \n";

			//Get user input
			for (int i = 0; i < 4; i++)
				cin.get(user[i]);

			cout << "This library is restricted. Unable to delete " << user << endl;
		}
		else if (menu == 3)
		{
			cout << "Please enter the index you would like records for:\n";

			//Get user input for single index
			cin.get(user[0]);

			cout << "We are a little tied up right now.  Check back later.\n";
		}
		else if (menu == 4)
		{
			cout << "TL;DR but if you insist...\n";

			me.print_library();
		}
		else if (menu == 5)
		{
			cout << "Well this is embarassing.  Looks like we never implemented this option...\n";

		}
		else if (menu == 6)
		{
			cout << "You must be crazy! Don't you know some programmer in a poor run down shack"
				<< "his whole life building this.  I hope you feel awful.\n";

			delete me;

			cout << "I guess this is the end.  Maybe I'll become a poet writer next.\n";
		}
		else if (menu == 7)
		{
			cout << "Thanks for visiting!\n";
			cin.get();
		}
	}
};
