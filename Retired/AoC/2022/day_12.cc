#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

struct State{
	int i, j, w;
	char letter;
	bool operator < (const State& o) const {
		return w > o.w;
	}
	State(int _i, int _j, int _w, char _letter):
		i(_i), j(_j), w(_w), letter(_letter) {}
};

int N = 41, M;
char a[MxN][MxN];
int dist[MxN][MxN];
string s;
pair<int, int> stp, edp;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline void solve1(){
	priority_queue<State> pq;
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(stp.first, stp.second, dist[stp.first][stp.second] = 0, 'a' - 1);
	a[edp.first][edp.second] = 'z' + 1;
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.i;
			int jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > N || jj > M){
				continue;
			}
			int nxt = now.w + 1;
			if(dist[ii][jj] > nxt && (now.letter == a[ii][jj] || now.letter + 1 == a[ii][jj])){
				pq.emplace(ii, jj, dist[ii][jj] = nxt, a[ii][jj]);
			}
		}
	}
	cout << "Answer #1: " << dist[edp.first][edp.second] << "\n";
	return ;
}

int main(){
	freopen("input.txt", "r", stdin);
	for(int i=1; i<=N; ++i){
		cin >> s;
		M = (int) s.size();
		for(int j=1; j<=s.size(); ++j){
			a[i][j] = s[j - 1];
		}
	}
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			if(a[i][j] == 'S'){
				stp = make_pair(i, j);
			}
			if(a[i][j] == 'E'){
				edp = make_pair(i, j);
			}
		}
	}
	solve1();
	return 0;
}

