#include <bits/stdc++.h>

using namespace std;

struct State{
	int i, j, k;
	State(int _i, int _j, int _k):
		i(_i), j(_j), k(_k) {}
};

const int MxN = 55;
bool points[MxN][MxN][MxN];
int a, b, c, max_a, max_b, max_c, it;

const int di[] = {-1, 1, 0, 0, 0, 0};
const int dj[] = {0, 0, -1, 1, 0, 0};
const int dk[] = {0, 0, 0, 0, -1, 1};

int main(){
	//cin.tie(nullptr)->ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int N = 2799;
	vector<State> p;
	for(int i=1; i<=N; ++i){
		//cin >> a >> "," >> b >> "," >> c;
		scanf("%d,%d,%d", &a, &b, &c);
		points[a][b][c] = true;
		max_a = max(max_a, a);
		max_b = max(max_b, b);
		max_c = max(max_c, c);
		p.emplace_back(a, b, c);
	}
	int cnt = 0;
	for(auto x: p){
		for(int k=0; k<6; ++k){
			int ii = di[k] + x.i;
			int jj = dj[k] + x.j;
			int kk = dk[k] + x.k;
			cnt += (!points[ii][jj][kk]);
		}
	}
	//cout << cnt << "\n";
	printf("Answer #1: %d\n", cnt);
	return 0;
}
