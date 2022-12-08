#include <bits/stdc++.h>

using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	string s;
	cin >> s;
	queue<char> q, u;
	for(int i=0; i<14; ++i){
		q.emplace(s[i]);
	}
	set<char> st;
	for(int i=14; i<s.size(); ++i){
		q.emplace(s[i]);
		st.clear();
		cerr << "D : ";
		while(q.size() > 14){
			q.pop();
		}
		u = q;
		while(!u.empty()){
			char now = u.front(); u.pop();
			cerr << now;
			st.emplace(now);
		}
		cerr << "\n";
		if(st.size() == 14){
			cout << i + 1 << "\n";
			break;
		}
	}
	return 0;
}
