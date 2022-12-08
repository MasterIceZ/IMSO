#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int sum = 0;
	int n = 300;
	for(int i=1; i<=n/3; ++i){
		string s, t, u;
		cin >> s >> t >> u;
		unordered_map<char, int> mp_a, mp_b, mp_c;
		for(auto x: s){
			mp_a[x]++;
		}
		for(auto x: t){
			mp_b[x]++;
		}
		for(auto x: u){
			mp_c[x]++;
		}
		for(char i='a'; i<='z'; ++i){
			if(mp_a[i] && mp_b[i] && mp_c[i]){
				sum += (i - 'a' + 1);
			}	
		}
		for(char i='A'; i<='Z'; ++i){
			if(mp_a[i] && mp_b[i] && mp_c[i]){
				sum += (i - 'A' + 27);
			}
		}
	}	
	cout << sum;
	return 0;
}
