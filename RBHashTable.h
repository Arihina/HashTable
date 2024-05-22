#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Tree.h"

using namespace std;

class RBHashTable
{
private:
	int countBuckets = 10;
	int testCount = 0;
	vector<RBTree> buckets;

	int hashCode(string elem)
	{
		int code = hash<string>()(elem);
		return abs(code) % countBuckets;
	}

	void init()
	{
		for (int i = 0; i < countBuckets; i++)
		{
			RBTree tree;
			buckets.push_back(tree);
		}
		buckets.shrink_to_fit();
	}

public:
	RBHashTable()
	{
		init();
	}

	RBHashTable(int countBuckets)
	{
		this->countBuckets = countBuckets;
		init();
	}

	void put(string elem)
	{
		int code = hashCode(elem);
		if (!buckets[code].search(elem))
		{
			buckets[code].insert(elem);
		}
	}

	void remove(string elem)
	{
		int code = hashCode(elem);
		if (buckets[code].search(elem))
		{
			buckets[code].remove(elem);
		}
		
	}

	void prettyPrint()
	{
		cout << "Hash Table with Red Black tree" << endl << endl;
		cout << "Buckets" << endl;

		for (int i = 0; i < countBuckets; i++)
		{
			cout << "Value of Hash Code " << i << endl;
			cout << "\tElements of bucket" << endl;
			cout << "\t\t";
			buckets[i].printValue();
			cout << endl << endl;
		}

		cout << endl;
	}
};