#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;
using ll = long long;

struct vertex_t {
	string v;
	int a, b;
	vertex_t(string _v, int _a, int _b):
		v(_v), a(_a), b(_b) {}
};

unordered_map<string, vector<vertex_t>> adj;
string b;
pair<ll, ll> answer;

ll gcd(ll a, ll b) {
	if(a % b == 0ll) {
		return b;
	}
	return gcd(b, a % b);
}

void dfs(string u, string p, ll val_a, ll val_b) {
	if(u == b) {
		answer = make_pair(val_a, val_b);
		return ;
	}
	for(auto &[v, a, b]: adj[u]) {
		if(v == p) {
			continue;
		}
		ll aa = val_a * a, bb = val_b * b;
		ll g = gcd(aa, bb);
		aa /= g;
		bb /= g;
		dfs(v, u, aa, bb);
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	while(true) {
		string opr, _;
		cin >> opr;
		if(opr == ".") {
			break;
		}
		if(opr == "!") {
			int x, y;
			string a, b;
			cin >> x >> a >> _ >> y >> b;
			adj[a].emplace_back(b, x, y);
			adj[b].emplace_back(a, y, x);
		}
		else {
			string a;
			cin >> a >> _ >> b;
			answer = make_pair(-1ll, -1ll);
			dfs(a, "", 1, 1);
			if(answer == make_pair(-1ll, -1ll)) {
				cout << "? " << a << " = ? " << b << "\n";
			}
			else {
				cout << answer.first << " " << a << " = " << answer.second << " " << b << "\n";
			}
		}
	}
	return 0;
}
