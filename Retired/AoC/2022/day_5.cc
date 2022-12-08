#include <bits/stdc++.h>

using namespace std;

deque<char> q[10];

void init(){
	vector<vector<char>> v(10);
	v[1] = {'G', 'T', 'R', 'W'};
	v[2] = {'G', 'C', 'H', 'P', 'M', 'S', 'V', 'W'};
	v[3] = {'C', 'L', 'T', 'S', 'G', 'M'};
	v[4] = {'J', 'H', 'D', 'M', 'W', 'R', 'F'};
	v[5] = {'P', 'Q', 'L', 'H', 'S', 'W', 'F', 'J'};
	v[6] = {'P', 'J', 'D', 'N', 'F', 'M', 'S'};
	v[7] = {'Z', 'B', 'D', 'F', 'G', 'C', 'S', 'J'};
	v[8] = {'R', 'T', 'B'};
	v[9] = {'H', 'N', 'W', 'L', 'C'};
	for(int i=1; i<=9; ++i){
		for(auto x: v[i]){
			q[i].emplace_back(x);
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	init();
	int N = 501;
	deque<char> t;
	for(int i=1; i<=N; ++i){
		int n, from, to;
		scanf("move %d from %d to %d\n", &n, &from, &to);
		//printf("D: %d %d %d\n", n, from, to);
		while(n--){
			t.emplace_back(q[from].back());
			q[from].pop_back();
		}
		while(!t.empty()){
			q[to].emplace_back(t.back());
			t.pop_back();
		}
	}
	for(int i=1; i<=9; ++i){
		printf("%c", q[i].back());
	}
	printf("\n");
	return 0;
}
