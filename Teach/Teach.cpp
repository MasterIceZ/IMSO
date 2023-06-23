#include <bits/stdc++.h>
using namespace std;

int parent[111];

int find_root(int u){
	if(parent[u] == u) {
		return u;
	}
	return find_root(parent[u]);
}

int main() {
	for(int i=1; i<=10; ++i){
		parent[i] = i;
	}
	parent[1] = 3;
	parent[2] = 3;
	parent[3] = 3;
	parent[4] = 7;
	parent[5] = 7;
	parent[6] = 6;
	parent[7] = 6;
	
	for(int i=1; i<=7; ++i) {
		cout << "Parent of #" << i << ": " << find_root(i) << "\n";
	}	

	return 0;
}
