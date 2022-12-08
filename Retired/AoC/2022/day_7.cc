#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> adj;
map<string, string> pre;
map<string, long long> v, dp;
map<string, bool> visited;

const long long bound = 100000;
long long answer = 0ll;

void dfs(string u){
	cerr << "Current: " << u << "\n";
	visited[u] = true;
	for(auto x: adj[u]){
		if(visited[x] || v[x]){
			continue;
		}
		dfs(x);
	}
	long long sum = 0ll;
	for(auto x: adj[u]){
		if(visited[x] || !v[x]){
			continue;
		}
		sum += v[x];
	}
	if(sum <= bound){
		answer += sum;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int n = 1027;
	string it = "";
	for(int i=1; i<=n; ++i){
		string a;
		cin >> a;
		if(a == "$"){
			string b;
			cin >> b;
			if(b == "cd"){
				string c;
				cin >> c;
				if(c == ".."){
					it = pre[it];
				}
				else{
					it = c;
				}
			}
		}
		else{
			string name;
			cin >> name;
			if(a == "dir"){
				adj[it].emplace_back(name);
				pre[name] = it;
			}
			else{
				v[name] = stoll(a);
			}
		}
	}
	dfs("/");
	cout << answer;
	return 0;
}
