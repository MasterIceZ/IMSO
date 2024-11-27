#include <vector>
#include <array>

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
