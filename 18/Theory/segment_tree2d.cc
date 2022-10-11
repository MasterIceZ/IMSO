// written by Hydrolyzed~

#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;
int a[MxN][MxN], n, m;

struct Segment_Tree{
	int tree[MxN << 2][MxN << 2];
	void build_col(int l_i, int r_i, int l_j, int r_j, int idx_i, int idx_j){
		if(l_j > r_j){
			return ;
		}
		if(l_j == r_j && l_i == r_i){	
			tree[idx_i][idx_j] = a[l_i][l_j];
			return ;
		}
		if(l_j == r_j){
			tree[idx_i][idx_j] = tree[idx_i << 1][idx_j] + tree[idx_i << 1 | 1][idx_j];
			return ;
		}
		int mid = (l_j + r_j) >> 1;
		build_col(l_i, r_i, l_j, mid, idx_i, idx_j << 1);
		build_col(l_i, r_i, mid + 1, r_j, idx_i, idx_j << 1 | 1);
		tree[idx_i][idx_j] = tree[idx_i][idx_j << 1] + tree[idx_i][idx_j << 1 | 1];
	}
	void build_row(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){
			build_col(l, r, 1, m, idx, 1);
			return ;
		}
		int mid = (l + r) >> 1;
		build_row(l, mid, idx << 1);
		build_row(mid + 1, r, idx << 1 | 1);
		build_col(l, r, 1, m, idx, 1);
	}
	void build(){
		build_row(1, n, 1);
	}
	void update_col(int l_i, int r_i, int l, int r, int id_i, int id_j, int v, int idx_i, int idx_j){
		if(l > r || l > id_j || r < id_j){
			return ;
		}
		if(l == r && l_i == r_i){
			tree[idx_i][idx_j] = v;
			return ;
		}
		if(l == r){
			tree[idx_i][idx_j] = tree[idx_i << 1][idx_j] + tree[idx_i << 1 | 1][idx_j];
			return ;
		}
		int mid = (l + r) >> 1;
		update_col(l_i, r_i, l, mid, id_i, id_j, v, idx_i, idx_j << 1);
		update_col(l_i, r_i, mid + 1, r, id_i, id_j, v, idx_i, idx_j << 1 | 1);
		tree[idx_i][idx_j] = tree[idx_i][idx_j << 1] + tree[idx_i][idx_j << 1 | 1];
	}
	void update_row(int l, int r, int id_i, int id_j, int v, int idx){
		if(l > r || l > id_i || r < id_i){
			return ;
		}
		if(l == r){
			update_col(l, r, 1, m, id_i, id_j, v, idx, 1);
			return ;
		}
		int mid = (l + r) >> 1;
		update_row(l, mid, id_i, id_j, v, idx << 1);
		update_row(mid + 1, r, id_i, id_j, v, idx << 1 | 1);
		update_col(l, r, 1, m, id_i, id_j, v, idx, 1);
	}
	void update(int i, int j, int v){
		update_row(1, n, i, j, v, 1);
	}
	int read_col(int l, int r, int wl, int wr, int idx_i, int idx_j){
		if(l > r || l > wr || r < wl){
			return 0;
		}
		if(wl <= l && r <= wr){
			return tree[idx_i][idx_j];
		}
		int mid = (l + r) >> 1;
		return read_col(l, mid, wl, wr, idx_i, idx_j << 1) + read_col(mid + 1, r, wl, wr, idx_i, idx_j << 1 | 1);
	}
	int read_row(int l, int r, int wl_i, int wr_i, int wl_j, int wr_j, int idx){
		if(l > r || l > wr_i || r < wl_i){
			return 0;
		}
		if(wl_i <= l && r <= wr_i){
			return read_col(1, m, wl_j, wr_j, idx, 1);
		}
		int mid = (l + r) >> 1;
		return read_row(l, mid, wl_i, wr_i, wl_j, wr_j, idx << 1) + read_row(mid + 1, r, wl_i, wr_i, wl_j, wr_j, idx << 1 | 1);
	}
	int read(int a, int b, int c, int d){
		return read_row(1, n, a, c, b, d, 1);
	}
} seg;

// call build() to initial with array `a`
// call update(a, b, value) to set tree[a][b] = value
// call read(a, b, c, d) to read value in rectangle (a, b) to (c, d)


// toi8_location


int main(){
	int k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf("%d", &a[i][j]);
			seg.update(i, j, a[i][j]);
		}
	}
//	seg.build();
//	cout << seg.read(1, 1, 1, 2);
	int answer = -1e9 - 100;
	for(int i=k; i<=n; ++i){
		for(int j=k; j<=m; ++j){
			answer = max(answer, seg.read(i - k + 1, j - k + 1, i, j));
		}
	}
	printf("%d", answer);
	return 0;
}

// https://graphsketch.com/?eqn1_color=1&eqn1_eqn=%28log%28x%29%2Flog%282%29%29%5E2&eqn2_color=2&eqn2_eqn=x&eqn3_color=3&eqn3_eqn=&eqn4_color=4&eqn4_eqn=&eqn5_color=5&eqn5_eqn=&eqn6_color=6&eqn6_eqn=&x_min=0&x_max=100&y_min=0&y_max=100&x_tick=1&y_tick=1&x_label_freq=5&y_label_freq=5&do_grid=0&do_grid=1&bold_labeled_lines=0&bold_labeled_lines=1&line_width=4&image_w=850&image_h=525
