#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    string s, t, x;
    cin >> s;
    int n = s.size() - 1;
    for(int i=1; i<=n; ++i){
        t += s[i];
    }
    stringstream ss(t);
    vector<long long> v;
    while(getline(ss, x, ',')){
        v.emplace_back(stoll(x));
    }
    sort(v.begin(), v.end(), greater<long long> ());
    for(auto x: v){
        cout << x << " ";
    }
    return 0;
}
