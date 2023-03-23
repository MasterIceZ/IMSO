#include <bits/stdc++.h>
#include "testlib.h"
#include "aquagenlib.h"

using namespace std;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int min_N = atoi(argv[1]);
	int max_N = atoi(argv[2]);
	int max_M = atoi(argv[3]);
	int max_K = atoi(argv[4]);
	int q = 3;
	cout << q << "\n";
	while(q--){
		int N = rnd.next(min_N, max_N);
		int M = rnd.next(N, max_M);
		int K = rnd.next(1, max_K);
		int S = rnd.next(1, N);
		cout << N << " " << M << " " << K << " " << S << "\n";
		vector<pair<int, int>> g = gen_directed_graph(N, M);
		for(auto x: g){
			cout << x.first + 1 << " " << x.second + 1 << "\n";
		}
	}
	return 0;
}
