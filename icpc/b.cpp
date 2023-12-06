#include <bits/stdc++.h>

using namespace std;

void printBit(bitset<32> b) {
	for(int i=32; i>=0; --i) {
		cout << (b[i] ? "1": "0");
	}
	cout << "\n";
	return ;
}

void printNumber(bitset<32> b) {
	int res = 0;
	for(int i=0; i<32; ++i) {
		if(b[i]) {
			res |= (1 << i);
		}
	}
	cout << res << "\n";
	return ;
}

int main() {
	bitset<32> a = 10;
	bitset<32> b = 9;
	printBit(a);
	printBit(b);
	printBit(a ^ b);
	return 0;
}
