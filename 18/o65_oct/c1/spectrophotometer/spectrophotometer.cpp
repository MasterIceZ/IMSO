#include "spectrophotometer.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[5];
int comp[1010];

bool try_call(int a, int b){
	if(call_swap(a, b) == 1){
		return true;
	}
	call_swap(a, b);
	return false;
}

void hand_assert(int N){
	if(N > 3){
		while(1);
	}
}

void sort_lasers(int N) {
//	assert(N <= 3);
	hand_assert(N);
	if(N > 3){
		exit(0);
	}
	if(N == 1){
		return ;
	}
	vector<vector<bool>> isSame(3 * N, vector<bool> (3 * N, false));
	for(int i=0; i<3 * N; ++i){
		for(int j=i+1; j<3 * N; ++j){
			isSame[i][j] = try_call(i, j);
		}
	}
	for(int i=0, it = 0; i<3 * N; ++i){
		if(comp[i]){
			continue;
		}
		comp[i] = ++it;
		adj[it - 1].emplace_back(i);
		for(int j=i+1; j<3 * N; ++j){
			if(isSame[i][j]){
				comp[j] = it;
				adj[it - 1].emplace_back(j);
			}
		}
	}
	vector<int> a(3 * N), expected(3 * N);
	for(int i=0; i<3; ++i){
		for(int j=0; j< (int) adj[i].size(); ++j){
			a[adj[i][j]] = i;
			expected[i * 3 + j] = i;
		}
	}
#ifdef _DEBUG
	cout << "A : ";
	for(auto x: a){
		cout << x << " ";
	}
	cout << "\n";
	cout << "E : ";
	for(auto x: expected){
		cout << x << " ";
	}
	cout << "\n";
#endif
	if(a == expected){
		return ;
	}
	bool ok = true;
	for(int state=0; state<3; ++state){
		sort(adj[state].begin(), adj[state].end());
		for(int i=1; i<adj[state].size(); ++i){
			ok &= (adj[state][i] - 1 == adj[state][i - 1]);
		}
	}
	if(ok){
		return ;
	}
	for(int state=0; state<3 * N - 1; ++state){
		for(int i=0; i<3 * N - 1; ++i){
			if(a[i] > a[i + 1]){
				call_swap(i, i + 1);
				swap(a[i], a[i + 1]);
			}
		}
	}
#ifdef _DEBUG
	cout << "A : ";
	for(auto x: a){
		cout << x << " ";
	}
	cout << "\n";
	cout << "E : ";
	for(auto x: expected){
		cout << x << " ";
	}
	cout << "\n";
#endif
//	assert(a == expected);
}
