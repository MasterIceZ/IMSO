#include <bits/stdc++.h>
using namespace std ;

bool on[100010];

int main() {
	int n = 100;
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; j+=i){
			on[j] ^= (i & 1);
		}
	}
	for(int i=1; i<=n; ++i){
		if(on[i]){
			cout << i << " ";
		}
	}
	return 0;
}
