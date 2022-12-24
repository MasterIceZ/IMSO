#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 2020;
int a[MxN];

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    vector<pair<int, int>> answer;
    for(int i=1; i<=n; ++i){
        if(a[i] > a[i - 1] && a[i] > a[i + 1]){
            answer.emplace_back(i - 1, a[i]);
        }
    }
    if(answer.empty()){
        cout << "There is no lift hill";
    }
    else if(answer.size() >= 2){
        cout << "There are " << answer.size() << " lift hills at index(height):";
        for(auto x: answer){
            cout << " " << x.first << "(" << x.second << ")";
        }
    }
    else{
        cout << "There is 1 lift hill at index(height): " << answer[0].first << "(" << answer[0].second << ")";
    }
    return 0;
}

