#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> v[3];
int it[2];

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1, x; i<=n; ++i){
        cin >> x;
        v[x % 2].emplace_back(x);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    it[0] = -1 * v[0].empty();
    it[1] = -1 * v[1].empty();
    for(int i=1; i <= 2 * max(v[0].size(), v[1].size()); ++i){
        int state = i % 2;
        if(it[state] != -1){
            cout << v[state][it[state]] << " ";
            it[state]++;
        }
        else{
            cout << 0 << " ";
        }
        if(it[state] == v[state].size()){
            it[state] = -1;
        }
    }
    return 0;
}
