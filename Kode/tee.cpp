#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

const int MxN = 100100;
int a[MxN];

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	stack<pair<int, int>> st;
	unorder_map<int, int> mp;
	for(int i=1; i<=n; ++i){
		while(!st.empty() && st.top() > a[i]){
			st.pop();
		}
		st.emplace(i, a[i]);
	}
	return 0;
}
