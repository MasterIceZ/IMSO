#include <bits/stdc++.h>

using namespace std;

struct node_t {
	int w, sum, p, child[2];
	bool reversed;
};

struct link_cut_tree {
	vector<node_t> nodes;
	int stk[333];

	link_cut_tree(int n):
		nodes(n + 1) {}
	void apply_reverse(int x) {
		if(x == 0) {
			return ;
		}
		swap(nodes[x].child[0], nodes[x].child[1]);
		nodes[x].reversed = !nodes[x].reversed;
	}
	void push_up(int x) {
		nodes[x].sum = nodes[x].w;
		if(nodes[x].child[0] != 0) {
			nodes[x].sum += nodes[nodes[x].child[0]].sum;
		}
		if(nodes[x].child[1] != 0) {
			nodes[x].sum += nodes[nodes[x].child[1]].sum;
		}
	}
	void push_down(int x) {
		if(nodes[x].reversed == false) {
			return ;
		}
		applyReverse(nodes[x].child[0]);
		applyReverse(nodes[x].child[1]);
		nodes[x].reversed = false;
	}
	bool is_splay_root(int x) {
		int p = nodes[x].p;
		return (nodes[p].child[0] != x && nodes[p].child[1] != x);
	}
	void rotate(int x) {
		int p = nodes[x].p;
		int g = nodes[p].p;
		bool dir = (nodes[p].child[1] == x);

		if(!is_splay_root(p)) {
			bool pd = (nodes[g].child[1] == p);
			nodes[g].child[pd] = x;
		}

		int b = nodes[x].child[!dir];
		nodes[p].child[dir] = b;
		if(b != 0) {
			nodes[b].p = p;
		}
		nodes[x].child[!dir] = p;
		nodes[p].p = x;
		nodes[x].p = g;

		push_up(p);
		push_up(x);
	}
	void splay(int x) {
		int t = 0, y = x;
		stk[t++] = x;
		while(!is_splay_root(y)) {
			stk[t++] = y = nodes[y].p;
		}
		while(t > 0) {
			push_down(stk[--t]);
		}

		while(!is_splay_root(x)) {
			int p = nodes[x].p;
			int g = nodes[p].p;
			if(!is_splay_root(p)) {
				bool zigzag = (nodes[p].child[1] == x) == (nodes[g].child[1] == p);
				rotate(zigzag ? p : x);
			}
			rotate(x);
		}
	}
	int access(int x) {
		int last = 0;
		for(int y=x; y!=0; y=nodes[y].p) {
			splay(y);
			nodes[y].child[1] = last;
			push_up(y);
			last = y;
		}
		return last;
	}
	void make_root(int x) {
		access(x);
		splay(x);
		applyReverse(x);
	}
	int find_root(int x) {
		access(x);
		splay(x);
		while(true) {
			push_down(x);
			if(nodes[x].child[0] == 0) {
				break;
			}
			x = nodes[x].child[0];
		}
		splay(x);
		return x;
	}
	bool link(int x, int y) {
		make_root(x);
		if(find_root(y) == x) {
			return false;
		}
		nodes[x].p = y;
		return true;
	}
	bool cut(int x, int y) {
		make_root(x);
		access(y);
		splay(y);
		if(nodes[y].child[] != x || nodex[x].child[1] == true) {
			return false;
		}
		nodes[y].child[0] = 0;
		nodes[x].p = 0;
		push_up(y);
		return true;
	}
	void toggle(int x) {
		splay(x);
		nodes[x].w = !nodes[x].w;
		push_up(x);
	}
	int query(int x, int y) {
		make_root(x);
		access(y);
		splay(y);
		return nodes[y].sum;
	}
} lct;

inline void solve() {
	int n, d;
	cin >> n >> d;

}

signed main(int argc char *argv[]) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
