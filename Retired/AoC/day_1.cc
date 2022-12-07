#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	vector<ll> v;
	string s;
	v.emplace_back(0ll);
	for(int i=1; i<=2237; ++i){
		getline(cin, s);
		if(s.size() == 0){
			v.emplace_back(0ll);
			continue;
		}
		else{
			v[v.size() - 1] += stoll(s);
		}
	}
	sort(v.begin(), v.end(), greater<ll> ());
	cout << v[0] + v[1] + v[2] << "\n";
}
