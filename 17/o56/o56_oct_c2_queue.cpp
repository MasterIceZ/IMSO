/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o56_oct_c2_queue
 * ALGO		: Fenwick Tree, Heap
 * DATE		: 7 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
struct Fenwick{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<=100000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

struct Patient{
	int id, prio;
	bool operator < (const Patient& o) const{
		return prio > o.prio;
	}
};

priority_queue<Patient> pq;
int a[MxN], current;

void solve(){
	int c, x, p;
	cin >> c;
	if(c == 1){
		current++;
		cin >> p;
		fw.update(p, 1);
		pq.push({current, p});
		a[current] = p;
	}
	else if(c == 2){
		if(pq.empty()){
			cout << 0 << "\n";
		}
		else{
			cout << pq.top().id << "\n";
			fw.update(pq.top().prio, -1);
//			dbg(pq.top().id, pq.top().prio);
			pq.pop();
		}
	}
	else if(c == 3){
		cin >> x;
		int id = a[x];
		cout << fw.read(id - 1)<< "\n";
	}

	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
