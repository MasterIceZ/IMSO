#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 22;
int n, a[MxN][MxN], answer = -1e9 - 100;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void walk(int i, int j){
//	printf("current position = (%d, %d)\n", i, j);
	answer = max(answer, a[i][j]);
	for(int k=0; k<4; ++k){
		int next_i = di[k] + i, next_j = dj[k] + j;
		// check boundary
		if(next_i < 1 || next_j < 1 || next_i > n || next_j > n){
			continue;
		}
		// can go ?
		if(a[next_i][next_j] == 100 || a[next_i][next_j] <= a[i][j]){
			continue;
		}
		walk(next_i, next_j);
	}
}

int main(){
	int st_x, st_y;
	scanf("%d %d %d", &n, &st_y, &st_x);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	walk(st_x, st_y);
	printf("%d\n", answer);
	return 0;
}
// icy
