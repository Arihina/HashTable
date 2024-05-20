#pragma once

#include <iostream>
#include <string>

#include "List.h"

using namespace std;

class HashTable
{
private:
	int countBuckets = 10;

	int hashCode(string item)
	{
		int code = 0;
		for (const auto& ch : item)
		{
			code += (int)ch;
		}

		return code % countBuckets;
	}

public:
	HashTable()
	{

	}

	HashTable(int countBuckets)
	{
		this->countBuckets = countBuckets;
	}

};