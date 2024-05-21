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
	vector<LinkedList<string>> buckets;

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
			LinkedList<string> lst;;
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


};