#include <bits/stdc++.h>
using namespace std;

const int MxN = 100010;

int parent[MxN], troop[MxN];

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

int main(){
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i){
		parent[i] = i;
		scanf("%d", &troop[i]);
	}
	while(m--){
		scanf("%d %d", &a, &b);
		int root_a = find_root(a);
		int root_b = find_root(b);
		if(root_a == root_b){
			printf("-1\n");
		}
		else if(troop[root_a] == troop[root_b]){
			printf("%d\n", min(root_a, root_b));
			troop[min(root_a, root_b)] += troop[max(root_a, root_b)] / 2;
			parent[max(root_a, root_b)] = min(root_a, root_b);
		}
		else if(troop[root_a] > troop[root_b]){
			printf("%d\n", root_a);
			troop[root_a] += troop[root_b] / 2;
			parent[root_b] = root_a;
		}
		else{
			printf("%d\n", root_b);
			troop[root_b] += troop[root_a] / 2;
			parent[root_a] = root_b;
		}
	}

	return 0;
}
