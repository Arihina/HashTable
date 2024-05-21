#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

int main()
{
	HashTable set;
	set.put("ABCD");
	set.put("ABCDE");
	set.put("ABCDEF");
	set.prettyPrint();

	set.remove("ABCD");
	set.prettyPrint();
}