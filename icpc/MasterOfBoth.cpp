#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MxN = 500050;
const int MxT = 1500010;
const int MxC = 33;
 
struct trie_t {
	int t[MxT][MxC], nodes = 0;
	ll cnt[MxT], mem[MxC][MxC];
	void insert(string s) {
		s += "`";
		int cur = 0;
		for(int i=0; i<(int) s.size(); ++i) {
			int cur_char = s[i] - 'a' + 1;
			if(t[cur][cur_char] == 0) {
				t[cur][cur_char] = ++nodes;	
			}
			for(int pre_char=0; pre_char<=26; ++pre_char) {
				if(cur_char == pre_char) {
					continue;
				}
				mem[pre_char][cur_char] += cnt[t[cur][pre_char]];
			}
			cur = t[cur][cur_char];
			cnt[cur] += 1;
		}
	}
	ll get(string p) {
		ll answer = 0ll;
		for(int i=0; i<26; ++i) {
			answer += mem[p[i] - 'a' + 1][0];
			for(int j=0; j<i; ++j) {
				answer += mem[p[i] - 'a' + 1][p[j] - 'a' + 1];
			}		
		}
		return answer;
	}
};
 
string s[MxN];
trie_t t;
 
signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> s[i];
		t.insert(s[i]);
	}
	while(q--) {
		string p;
		cin >> p;
		ll answer = t.get(p);
		cout << answer << "\n";
	}
	return 0;
}
