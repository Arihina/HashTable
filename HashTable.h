#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "List.h"

using namespace std;

class HashTable
{
private:
	int countBuckets = 10;
	int testCount = 0;
	vector<LinkedList> buckets;

	int hashCode(string elem)
	{
		int code = 0;
		for (const auto& ch : elem)
		{
			code += (int)ch;
		}

		return code % countBuckets;
	}

	void init()
	{
		for (int i = 0; i < countBuckets; i++)
		{
			LinkedList lst;
			buckets.push_back(lst);
		}
		buckets.shrink_to_fit();
	}

public:
	HashTable()
	{
		init();
	}

	HashTable(int countBuckets)
	{
		this->countBuckets = countBuckets;
		init();
	}

	void put(string elem)
	{
		int code = hashCode(elem);
		for (int i = 0; i < buckets[code].getLength(); i++)
		{
			if (buckets[code][i] == elem)
			{
				return;
			}
		}

		buckets[code].appendElem(elem);
	}

	void remove(string elem)
	{
		int code = hashCode(elem);

		if (buckets[code].getLength() == 1)
		{
			buckets[code].clear();
		}

		for (int i = 0; i < buckets[code].getLength(); i++)
		{
			if (elem == buckets[code][i])
			{
				buckets[code].deleteElem(i);
				break;
			}
		}
	}

	void prettyPrint()
	{
		cout << "Hash Table with Linked List" << endl << endl;
		cout << "Buckets" << endl;

		for (int i = 0; i < countBuckets; i++)
		{
			cout << "Bucket id " << i << endl;
			cout << "\tElements of bucket" << endl;
			cout << "\t\t";

			for (int j = 0; j < buckets[i].getLength(); j++)
			{
				cout << buckets[i][j] << " ";
			}
			cout << endl << endl;
		}

		cout << endl;
	}

	~HashTable()
	{
		for (int i = 0; i < buckets.size(); i++)
		{
			buckets[i].clear();
		}
	}
};