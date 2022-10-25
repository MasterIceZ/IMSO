#include <bits/stdc++.h>
#include "testlib.h"
#include "aquagenlib.h"

using namespace std;

int N, M, Q;
unordered_map<int, int> mp;

bool ok(vector<pair<int, int>> adj){
	int cnt = 0;
	int sq = sqrt(N);
	mp.clear();
	for(auto x: adj){
		mp[x.first]++, mp[x.second]++;
	}
	int maxx = 0;
	for(auto x: mp){
		maxx = max(maxx, x.second);
		if(x.second > sq){
			cnt++;
		}
	}
	return cnt >= (sq / 2);
}

vector<pair<int, int>> gen_undirected_graph_2(int N, int M){
	vector<pair<int, int>> adj;
	int cnt_big_node = rnd.next(1, 30);
	int sqr = 400;
	for(int i=1; i<=n; ++i){
		set<int> st;
		for(auto x: st){
			if(adj[x].first == 1){
				
			}
		}
	}
	return adj;
}

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	N = atoi(argv[1]);
	M = atoi(argv[2]);
	Q = atoi(argv[3]);
	vector<pair<int, int>> adj;
	int c = 0;
	if(N > 1000){
		do{
			adj = gen_undirected_graph_2(N, M);
		}while(!ok(adj));
	}
	else{
		adj = gen_undirected_graph(N, M);
	}
	cout << N << " " << M << "\n";
	for(auto x: adj){
		cout << x.first << " " << x.second << "\n";
	}
	cout << Q << "\n";
	while(Q--){
		int opr = rnd.next(1, 3);
		if(opr <= 2){
			// Update
			cout << "U " << rnd.next(1, N) << " " << rnd.next(1, 100) << "\n";
		}
		else{
			// Query
			cout << "Q " << rnd.next(1, N) << "\n";
		}
	}
	return 0;
}
