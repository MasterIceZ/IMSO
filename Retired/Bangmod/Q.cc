#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> v, answer;
bool done = false;
int n;

inline bool ok(int i, int j){
    for(int k=0; k<n; ++k){
        if(v[k][j]){
            return false;
        }
        if(v[i][k]){
            return false;
        }
    }
    for(int k=i, l=j; k<n && l>=0; ++k, --l){
        if(v[k][l]){
            return false;
        }
    }
    for(int k=i, l=j; k>=0 && l>=0; --k, --l){
        if(v[k][l]){
            return false;
        }
    }
    return true;
}

void rec(int state){
    if(done){
        return ;
    }
    if(state == n){
        done = true;
        answer = v;
        return ;
    }
    cerr << state << "\n";
    for(auto x: v){
        for(auto y: x){
            cerr << y << " ";
        }
        cerr << "\n";
    }
    cerr << "==================\n";
    for(int i=0; i<n; ++i){
        if(!ok(i, state)){
            continue;
        }
        v[i][state] = 1;
        cerr << "send " << i << ", " << state << "\n";
        rec(state + 1);
        v[i][state] = 0;
        if(done){
            return ;
        }
    }
    cerr << "ENDED\n";
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin >> n;
    v.resize(n, vector<int> (n));
    rec(0);
    if(done){
        for(auto x: answer){
            for(auto y: x){
                cout << y << " ";
            }
            cout << "\n";
        }
    }
    else{
        cout << "None";
    }
    return 0;
}



