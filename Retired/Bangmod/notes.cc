#include <bits/stdc++.h>
using namespace std;

using ll = long long;

char v[5];

vector<vector<char>> answer;
vector<char> t;
unordered_map<char, double> mp;
vector<int> vv = {'W', 'H', 'Q', 'E', '-'};
double a, b;

void rec(int state){
    if(state == 5){
        double sum = 0;
        t.clear();
        for(int i=1; i<=4; ++i){
            sum += mp[v[i]];
            t.emplace_back(v[i]);
        }
        if(sum == a){
            answer.emplace_back(t);
        }
        return ;
    }
    if(v[state] != 'X'){
        rec(state + 1);
    }
    else{
        for(auto x: vv){
            v[state] = x;
            rec(state + 1);
            v[state] = 'X';
        }
    }
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin >> a >> b;
    mp['-'] = 0;
    mp['W'] = 1 * b;
    mp['H'] = 0.5 * b;
    mp['Q'] = 0.25 * b;
    mp['E'] = 0.125 * b;
    for(int i=1; i<=4; ++i){
        cin >> v[i];
    }
    rec(1);
    for(auto x: answer){
        for(auto y: x){
            cout << y << " ";
        }
        cout << "\n";
    }
    if(answer.empty()){
        cout << "Impossible";
    }
    return 0;
}

