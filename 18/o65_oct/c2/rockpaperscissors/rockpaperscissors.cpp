#include "rockpaperscissors.h"
#include <bits/stdc++.h>

using namespace std;

set<vector<int>> used;
unordered_map<int, int> cnt;

int find_cheater1(int N){
	int question_1 = tournament({1, 2, 3, 4, 5});
	vector<int> v, s;
	if(question_1 == 5){
		v = {1, 2, 3, 4, 5};
	}
	else{
		v = {5, 6, 7, 8, 9};
	}
	do{
		s = {0, v[0], v[1], v[2], v[3]};
		sort(s.begin(), s.end());
		if(used.count(s)){
			continue;
		}
		used.emplace(s);
		int r = tournament(s);
		if(r == 4){
			for(auto x: s){
				cnt[x]++;
			}
		}
	}while(next_permutation(v.begin(), v.end()));
	int maxx = 0, idx = -1;
	for(int i=1; i<=3*N; ++i){
		if(cnt[i] > maxx){
			maxx = cnt[i];
			idx = i;
		}
	}
	return idx;
}

int find_cheater2(int N){
	for(int i=1; i<=n; ++i){
	}
	return 1;
}
