#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 66;
int n, m;
char a[MxN][MxN], b[MxN][MxN];
queue<pair<int, int>> q;

const int di[] = {-1, 0, 0, 1}, dj[] ={0, -1, 1, 0};

inline bool checkTree(int x_1, int y_1, int x_2, int y_2){
	for(int i=x_1; i<=x_2; ++i){
		for(int j=y_1; j<=y_2; ++j){
			if(a[i][j] == 'T'){
				return true;
			}
		}
	}
	return false;
}

// void fillSpace(int i, int j){
// 	b[i][j] = 'S';
// 	for(int k=0; k<4; ++k){
// 		int next_i = di[k] + i;
// 		int next_j = dj[k] + j;
// 		if(next_i < 1 || next_j < 1 || next_i > n || next_j > m){
// 			continue;
// 		}
// 		if(b[next_i][next_j] != 'P'){
// 			continue;
// 		}
// 		fillSpace(next_i, next_j);
// 	}
// }

void fillSpace(int start_x, int start_y){
	q.emplace(start_x, start_y);
	b[start_x][start_y] = 'S';
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		for(int k=0; k<4; ++k){
			int next_i = di[k] + now.first, next_j = dj[k] + now.second;
			if(next_i < 1 || next_j < 1 || next_i > n || next_j > m){
				continue;
			}
			if(b[next_i][next_j] != 'P'){
				continue;
			}
			q.emplace(next_i, next_j);
			b[next_i][next_j] = 'S';
		}
	}
}

int countPound(int x_1, int y_1, int x_2, int y_2){
	int cnt = 0;
	memcpy(b, a, sizeof a);
	for(int i=x_1; i<=x_2; ++i){
		for(int j=y_1; j<=y_2; ++j){
			if(b[i][j] != 'P'){
				continue;
			}
			fillSpace(i, j);
			cnt++;
		}
	}
	return cnt;
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf(" %c", &a[i][j]);
		}
	}
	int max_size = min(n, m), min_pound = 1e9 + 100;
	bool done = false;
	for(int current_size=max_size; current_size>=1; --current_size){
		// (i, j) => bottom right
		for(int i=current_size; i<=n; ++i){
			for(int j=current_size; j<=m; ++j){
				if(checkTree(i - current_size + 1, j - current_size + 1, i, j)){
					continue;
				}
				done = true;
				int pound = countPound(i - current_size + 1, j - current_size + 1, i, j);
				min_pound = min(min_pound, pound);
			}
		}
		if(done){
			printf("%d %d\n", current_size * current_size, min_pound);
			return 0;
		}
	}
	printf("0 0");
	return 0;
}
// icy
