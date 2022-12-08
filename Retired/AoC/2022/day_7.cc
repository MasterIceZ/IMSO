// dp on Tree
#include <bits/stdc++.h>

using namespace std;

using path_t = vector<string> ;

path_t current_path;
map<string, string> previous;
map<string, vector<string>> following;
map<string, long long> value, dp;
map<string, bool> visited;
long long sum = 0ll;

string create_path(path_t now){
	string res = "";
	for(auto x: now){
		res = res + x + "/";
	}
	return res;
}

long long dfs(string u){
	if(visited[u]){
		return dp[u];
	}
	visited[u] = true;
	dp[u] = value[u];
	for(auto x: following[u]){
		if(visited[x]){
			continue;
		}
		dp[u] += dfs(x);
	}
	return dp[u];
}

int main(){
	freopen("input.txt", "r", stdin);
	int n = 1027;
	string a, b, c;
	for(int i=1; i<=n; ++i){
		cin >> a;
		if(a == "$"){
			cin >> b;
			if(b == "cd"){
				cin >> c;
				if(c != ".."){
					current_path.emplace_back(c);
				}
				else{
					current_path.pop_back();
				}
			}
		}
		else{
			cin >> b;
			if(a == "dir"){
				string last = create_path(current_path);
				path_t next_path = current_path;
				next_path.emplace_back(b);
				string current = create_path(next_path);
				previous[current] = last;
				following[last].emplace_back(current);
			}
			else{
				string current = create_path(current_path);
				value[current] += stoll(a);
			}
		}
	}
	string start_point = create_path({"/"});
	dfs(start_point);
	vector<long long> vec;
	for(auto x: dp){
		if(x.second <= 100000ll){
			sum += x.second;
		}
		vec.emplace_back(x.second);
	}
	cout << "Answer #1: " << sum << "\n";
	vec.emplace_back(0ll);
	sort(vec.begin(), vec.end());
	long long all_space = 70000000ll;
	long long used_space = dp[start_point];
	cerr << "Used Space : " << used_space << "\n";
	long long remain = all_space - used_space;
	long long wanted = 30000000ll;
	long long erasing = wanted - remain;
	auto t = lower_bound(vec.begin(), vec.end(), erasing);
	cout << "Anser #2: " << *t << "\n";
	return 0;
}
