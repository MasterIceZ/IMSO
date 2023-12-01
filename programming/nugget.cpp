#include <bits/stdc++.h>

using namespace std;

int n;
bool printed = false;
bitset<110> b;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n;
	b[0] = true;
	for(int i=0; i<=n; i+=6) {
		b |= b << 6;	
	}
	for(int i=0; i<=n; i+=9) {
		b |= b << 9;
	}
	for(int i=0; i<=n; i+=20) {
		b |= b << 20;
	}
	for(int i=1; i<=n; ++i) {
		if(b[i] == 0) {
			continue;
		}
		cout << i << "\n";
		printed = true;
	}
	if(!printed) {
		cout << "no\n";
	}
	return 0;
}
