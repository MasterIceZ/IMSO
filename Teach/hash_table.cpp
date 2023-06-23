#include <bits/stdc++.h>

using namespace std;

const int HASH_SIZE = 1e6 + 3;

int real_value[HASH_SIZE], hashed_value[HASH_SIZE];

void add_key(int key, int value) {
	int hash_key = key % HASH_SIZE;
	while(hashed_value[hash_key] != 0){
		hash_key = (hash_key + 1) % HASH_SIZE;
	}
	hashed_value[hash_key] = value;
	real_value[hash_key] = key;
}

int read_key(int key) {
	int hash_key = key % HASH_SIZE;
	while(hashed_value[hash_key] != 0){
		// correct
		if(real_value[hash_key] == key) {
			return hashed_value[hash_key];
		}
		hash_key = (hash_key + 1) % HASH_SIZE;
	}
	// if not found
	return -999;
}

// write hash function
int hash_function(string key) {
	int hash_key = 0;
	for(auto x: key) {
		hash_key = (hash_key * 29) % HASH_SIZE;
		hash_key = (hash_key + (x - 'a')) % HASH_SIZE;
	}
	return hash_key;
}

int main() {

	add_key(hash_function("hello"), 12);
	add_key(hash_function("hi"), 55);

	printf("value of table[\"hello\"] = %d\n", read_key(hash_function("hello")));
	printf("value of table[\"hi\"] = %d\n", read_key(hash_function("hi")));
	printf("value of table[\"world\"] = %d\n", read_key(hash_function("world")));

//	std::map<string, int> table;
	std::unordered_map<string, int> table;
	table["hello"] = 12;
	table["hi"] = 55;
	printf("value of table[\"hello\"] = %d\n", table["hello"]);

	return 0;
}
