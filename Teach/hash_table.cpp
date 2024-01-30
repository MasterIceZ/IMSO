#include <bits/stdc++.h>

using namespace std;

const int HASH_SIZE = 1e6 + 3;

int real_value[HASH_SIZE]; // value of table[key]
string hashed_value[HASH_SIZE]; // value of key after hash

// write hash function
int hash_function(string key) {
  int hash_key = 0;
  for (auto x : key) {
    hash_key = (hash_key * 29) % HASH_SIZE;
    hash_key = (hash_key + (x - 'a')) % HASH_SIZE;
  }
  return hash_key;
}

// Linear Probing
void add_key(string key, int value) {
	int hash_key = hash_function(key) % HASH_SIZE;
	while(real_value[hash_key] != 0){
		hash_key = (hash_key + 1) % HASH_SIZE;
	}
  real_value[hash_key] = value;
  hashed_value[hash_key] = key;
}

int find_key(string key) {
	int hash_key = hash_function(key) % HASH_SIZE;
	while(real_value[hash_key] != 0) {
		// found!
		if(hashed_value[hash_key] == key) {
			return real_value[hash_key];
		}
		hash_key = (hash_key + 1) % HASH_SIZE;
	}
	// not found
	return -999;
}

int main() {

	add_key("hello", 12);
	add_key("hi", 55);

	printf("value of table[\"hello\"] = %d\n", find_key("hello"));
	printf("value of table[\"hi\"] = %d\n", find_key("hi"));
	printf("value of table[\"world\"] = %d\n", find_key("world"));

	return 0;
}
