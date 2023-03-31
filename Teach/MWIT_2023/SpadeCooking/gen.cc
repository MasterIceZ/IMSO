#include <bits/stdc++.h>
#include "aquagenlib.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int min_N = atoi(argv[1]);
	int max_N = atoi(argv[2]);
	int min_M = atoi(argv[3]);
	int max_M = atoi(argv[4]);
	int min_K = atoi(argv[5]);
	int max_K = atoi(argv[6]);
	int n = rnd.next(min_N, max_N);
	int m = rnd.next((long long) min_M, min(1ll*n*(n - 1ll) / 2ll, (long long) max_M));
	int k = rnd.next(min_K, max_K);
	int p = rnd.next(0, min(20, n));
	vector<pair<int, int>> g = gen_undirected_graph(n, m);
	cout << n << " " << m << " " << p << " " << k << "\n";
	for(auto edge: g){
		int w = rnd.next(1, 10000);
		cout << edge.first << " " << edge.second << " " << w << "\n";
	}
	set<int> st;
	vector<int> sts;
	while(st.size() != p){
		int now = rnd.next(1, n);
		st.emplace(now);
	}
	for(auto x: st){
		sts.emplace_back(x);
	}
	shuffle(sts.begin(), sts.end());
	if((int) sts.size() > 0){
		cout << sts[0];
		for(int i=1; i<(int) sts.size(); ++i){
			cout << " " << sts[i];
		}
	}
	cout << "\n";
	int stp = rnd.next(1, n);
	while(st.count(stp)){
		stp = rnd.next(1, n);
	}
	cout << stp << "\n";
	return 0;
}
