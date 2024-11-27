#include <bits/stdc++.h>

using namespace std;

template<size_t S>
struct binary_trie {
	vector<array<int, 2>> t = {array<int, 2> ()};
	vector<int> cnt = {0};
	int cnt_nodes = 0;

	int get_bit(int b, int i) {
		return (b & (1 << i)) ? 1: 0;
	}

	void insert(int v) {
		int cur = 0;
		cnt[0]++;
		for(int i=(int) S-1; i>=0; --i) {
			int bit = get_bit(v, i);
			if(!t[cur][bit]) {
				t[cur][bit] = ++cnt_nodes;
				t.emplace_back(array<int, 2> ());
				cnt.emplace_back(0);
			}
			cnt[t[cur][bit]]++;
			cur = t[cur][bit];
		}
	}

	void remove(int v) {
		int cur = 0;
		cnt[0]--;
		for(int i=(int) S-1; i>=0; --i) {
			int bit = get_bit(v, i);
			cnt[t[cur][bit]]--;
			cur = t[cur][bit];
		}
	}

	int get_min(int v) {
		int cur = 0, res = 0;
		for(int i=(int) S-1; i>=0; --i) {
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

	int get_max(int v) {
		int cur = 0, res = 0;
		for(int i=(int) S-1; i>=0; --i) {
			int bit = get_bit(v, i);
			if(t[cur][!bit] && cnt[t[cur][!bit]]) {
				res |= (1 << i);
				cur = t[cur][!bit];
			}
			else {
				cur = t[cur][bit];
			}
		}
		return res;
	}
};

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	binary_trie<30> t;
	set<int> st;
	while(q--) {
		int opr, x;
		cin >> opr >> x;
		if(opr == 0) {
			if(st.count(x)) {
				continue;
			}
			st.emplace(x);
			t.insert(x);
		}
		else if(opr == 1) {
			if(!st.count(x)) {
				continue;
			}
			st.erase(x);
			t.remove(x);
		}
		else {
			cout << t.get_min(x) << "\n";
		}
	}
}
