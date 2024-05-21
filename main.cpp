#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"
#include "RBHashTable.h"

using namespace std;

int main()
{
	HashTable* table;
	RBHashTable* tableRB;

	char answer;
	cout << "The default number of buckets for the hash table is 10. Change it? y/n " << endl;
	cin >> answer;

	if (answer == 'y')
	{
		cout << "Enter a number of buckets ";
		int num;
		cin >> num;
		table = new HashTable(num);
		tableRB = new RBHashTable(num);
	}
	else if (answer == 'n')
	{
		table = new HashTable();
		tableRB = new RBHashTable();
	}
	else
	{
		cout << "Invalid input";
		exit(1);
	}

	string item;
	string substring = "";
	vector<string> substrings;

	cout << "Enter a string to parse by space" << endl;
	getline(cin, item);
	getline(cin, item);

	item += " ";

	for (int i = 0; i < item.size(); i++)
	{
		if (item[i] != ' ')
		{
			substring += item[i];
		}
		else
		{
			substrings.push_back(substring);
			substring = "";
		}
	}

	for (int i = 0; i < substrings.size(); i++)
	{
		table->put(substrings[i]);
		tableRB->put(substrings[i]);
	}

	table->prettyPrint();
	cout << endl;
	tableRB->prettyPrint();
	cin >> answer;
}