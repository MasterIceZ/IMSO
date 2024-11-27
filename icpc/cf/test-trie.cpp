#include <bits/stdc++.h>

using namespace std;
using node_t = array<int, 2>;

struct trie_t {
	vector<node_t> t = {node_t()};
	vector<int> cnt = {0};
	int cnt_nodes = 0;

	int get_bit(int b, int i) {
		return (b & (1 << i)) ? 1: 0;
	}

	void remove(int v) {
		cnt[0]--;
		int cur = 0;
		for(int i=30; i>=0; --i) {
			int bit = get_bit(v, i);
			cnt[t[cur][bit]]--;
			cur = t[cur][bit];
		}
	}

	void insert(int v) {
		cnt[0]++;
		int cur = 0;
		for(int i=30; i>=0; --i) {
			int bit = get_bit(v, i);
			if(!t[cur][bit]) {
				t[cur][bit] = ++cnt_nodes;
				t.emplace_back(node_t());
				cnt.emplace_back(0);
			}
			cnt[t[cur][bit]]++;
			cur = t[cur][bit];
		}
	}
	
	int get_min(int v) {
		int cur = 0, res = 0;
		for(int i=30; i>=0; --i) {
			int bit = get_bit(v, i);
			if(t[cur][bit] && cnt[t[cur][bit]]) {
				cur = t[cur][bit];
			}
			else {
				res |= (1 << i);
				cur = t[cur][!bit];
			}
		}
		return res;
	}
};

signed main(int argc, char *argv[]) {
	trie_t t;
	t.insert(3);
	t.insert(4);

	cout << t.get_min(12) << "\n";

	t.remove(4);

	cout << t.get_min(12) << "\n";
	return 0;
}
