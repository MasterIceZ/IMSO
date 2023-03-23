#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int n = rnd.next(1, 100000);
	int k = rnd.next(1, n / 2);
	cout << n << " " << k << "\n";
	int w = rnd.next(1, 1000);
	cout << w;
	vector<int> leaf = {1};
	for(int i=2; i<=k; ++i){
		w = rnd.next(1, 1000);
		cout << " " << w;
		leaf.emplace_back(i);
	}
	cout << "\n";
	for(int i=k+1; i<=n; ++i){
		int idx = rnd.next(1, k - 1);
		int v = leaf[idx];
		leaf[idx] = i;
		w = rnd.next(1, 1000);
		cout << v << " " << w << "\n";
	}
	int q = rnd.next(10000, 100000);
	cout << q << "\n";
	for(int i=1; i<=q; ++i){
		int a = rnd.next(1, n);
		int b = rnd.next(1, n);
		cout << a << " " << b << "\n";
	}
	return 0;
}
