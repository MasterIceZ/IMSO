#include "magic.h"
#include <bits/stdc++.h>
using namespace std;

// case linear

const int HSH = 200003;
const int MxN = 200020;

vector<int> adj[MxN];
vector<pair<int, int>> edge;
int deg[MxN], name[MxN], it = 0;

struct fenwick{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<=200000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	int read(int idx){
		int res = 0;
		for(; idx > 0; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

vector<int> magic(int N, int M,int Q, vector<int>U, vector<int> V, vector<vector<int> >q){
	vector<int> res;
	for(auto query: q){
		if(query[0] == 0){
			fw.update(query[1] + 1, 1);
			res.emplace_back(0);
		}
		else{
			int cnt = fw.read(query[1]);
			if(cnt <= query[2]){
				res.emplace_back(1);
			}
			else{
				res.emplace_back(0);
			}
		}
	}
	return res;
}
