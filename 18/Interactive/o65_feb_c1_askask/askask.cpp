#include "askask.h"
#include <bits/stdc++.h>

using namespace std;

//std::vector<int> find_bombs(int N){
//	int lg = __lg(N);
//	cerr << "D : " << lg << "\n";
//	vector<vector<int>> send;
//	vector<int> tmp;
//	for(int i=0; i<lg; ++i){
//		send.emplace_back(tmp);
//	}
//	for(int i=0; i<N; ++i){
//		for(int mask = 0; mask<lg; ++mask){
//			if(i & (1 << mask)){
//				send[mask].emplace_back(i);
//			}
//		}
//	}
//	cerr << "D : " << send.size() << "\n";
//	vector<bool> res = analyse(send);
//	int answer = 0;
//	for(int i=0; i<res.size(); ++i){
//		if(!res[i]){
//			continue;
//		}
//		answer = (answer | (1 << i));
//	}
//	return {answer, answer};
//}

map<int, int> cnt;
int arr[10][10];

std::vector<int> find_bombs(int N){
	cnt.clear();
	vector<vector<int>> send;
	for(int i=0; i<8; ++i){
		vector<int> t;
		for(int j=0; j<8; ++j){
			t.emplace_back(i * 8 + j);	
			arr[i][j] = i * 8 + j;
		}
		send.emplace_back(t);
	}
	for(int j=0; j<8; ++j){
		vector<int> t;
		for(int i=0; i<8; ++i){
			t.emplace_back(i * 8 + j);
		}
		send.emplace_back(t);
	}
	for(int i=0; i<7; ++i){
		vector<int> t;
		for(int j=0, c=i; j<8; ++j){
			t.emplace_back(arr[c][j]);
			c = (c + 1) % 8;
		}
		send.emplace_back(t);
	}
	vector<bool> res = analyse(send);
	vector<int> r;
	for(int i=0; i<res.size(); ++i){
		if(!res[i]){
			continue;
		}
		for(auto x: send[i]){
			cnt[x]++;
		}
	}
	bool found = false;
	for(int i=0; i<8; ++i){
		if(res[i + 16]){
			found = true;
		}
	}
	if(!found){
		for(int j=0, c=7; j<8; ++j){
			cnt[arr[c][j]]++;
			c = (c + 1) % 8;
		}	
	}
	for(auto x: cnt){
		if(x.second == 3){
			r.emplace_back(x.first);
		}
	}
	if(r.size() == 1){
		r.emplace_back(r.back());
	}
	return r;
}
