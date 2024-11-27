#include <bits/stdc++.h>

using namespace std;

using node_t = array<int, 2>;
template<size_t S>
struct binary_trie {
  vector<node_t> t = {node_t()};
  vector<int> cnt = {0};
  int cnt_nodes = 0;
  void insert(int v) {
    int cur = 0;
    cnt[0]++;
    for(int i=S-1; i>=0; --i) {
      int b = (v & (1 << i)) ? 1: 0;
      if(!t[cur][b]) {
        t[cur][b] = ++cnt_nodes;
        t.emplace_back(node_t());
        cnt.emplace_back(0);
      }
      cnt[t[cur][b]]++;
      cur = t[cur][b];
    }
  }
  void remove(int v) {
    int cur = 0;
    cnt[0]--;
    for(int i=S-1; i>=0; --i) {
      int b = (v & (1 << i)) ? 1: 0;
      cnt[t[cur][b]]--;
      cur = t[cur][b];
    }
  }
  int get_min(int v) {
		int cur = 0, res = 0;
		for(int i=(int) S-1; i>=0; --i) {
      int b = (v & (1 << i)) ? 1 : 0;
      if(t[cur][b] && cnt[t[cur][b]]) {
				cur = t[cur][b];
			}
			else {
				res |= (1 << i);
				cur = t[cur][!b];
			}
		}
		return res;
	}

	int get_max(int v) {
		int cur = 0, res = 0;
		for(int i=(int) S-1; i>=0; --i) {
      int b = (v & (1 << i)) ? 1 : 0;
      if(t[cur][!b] && cnt[t[cur][!b]]) {
				res |= (1 << i);
				cur = t[cur][!b];
			}
			else {
				cur = t[cur][b];
			}
		}
		return res;
	}
};

int ask(int x, int y) {
	cout << "? " << x << " " << y << endl;
	int r;
	cin >> r;
	return r;
}

signed main(int argc, char *argv[]) {
	int t;
	cin >> t;
	while(t--) {
		binary_trie<30> trie;
		int n, answer = (1 << 30) - 1;
		cin >> n;
		for(int i=2; i<=n; ++i) {
			int v = ask(1, i);
			answer = min({answer, v, trie.get_min(v)});
			trie.insert(v);
		}
		cout << "! " << answer << endl;
	}
	return 0;
}
