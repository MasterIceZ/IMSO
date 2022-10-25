#include "rockpaperscissors.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;
int c[MxN];

int find_cheater1(int N){
	memset(c, 0, sizeof c);
	set<vector<int>> s;
	vector<int> v;
	for(int i=0; i<=3*N; ++i){
		v.emplace_back(i);
	}
	do{
		vector<int> send = {v[0], v[1], v[2]};
		if(s.count(send)){
			continue;
		}
		else{
			s.insert(send);
		}
		int r = tournament(send);
		if(r == 2){
			c[v[0]]++, c[v[1]]++, c[v[2]]++;
		}
	}while(next_permutation(v.begin(), v.end()));
	int maxx = -1, idx = -1;
	for(int i=0; i<=3*N; ++i){
		if(maxx < c[i]){
			maxx = c[i];
			idx = i;
		}
	}
	return idx;
}

int find_cheater2(int N){
  return 0;
}
