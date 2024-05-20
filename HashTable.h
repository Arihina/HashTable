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
	vector<LinkedList<int>> buckets;

	int hashCode(string item)
	{
		int code = 0;
		for (const auto& ch : item)
		{
			code += (int)ch;
		}

		return code % countBuckets;
	}

	void init()
	{
		for (int i = 0; i < countBuckets; i++)
		{
			LinkedList<int> lst;;
			buckets.push_back(lst);
		}
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
};