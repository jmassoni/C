// Insert and then lookup

// DO NOT EDIT THIS FILE
// DO NOT EDIT THIS FILE
// DO NOT EDIT THIS FILE
// DO NOT EDIT THIS FILE
// DO NOT EDIT THIS FILE

#include <hashtable.h>
#include <stdio.h>

int main() {
	HashTable *h = hashtableInit(10);
	hashtableInsert(h, "apple", "value1");
	char *value = hashtableLookup(h, "apple");
	printf("%s", value);
	return 0;
}