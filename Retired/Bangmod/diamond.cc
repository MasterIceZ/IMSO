#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> fibo(n + 1);
    vector<string> fibo_string(n + 1);
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<=n; ++i){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    for(int i=1; i<=n; ++i){
        fibo_string[i] = to_string(fibo[i]);
    }
    int max_size = fibo_string[n].size() + 1;
    for(int i=1; i<=n; ++i){
        string tmp;
        for(int j=fibo_string[i].size() + 1; j <= max_size; ++j){
            tmp += "_";
        }
        fibo_string[i] = tmp + fibo_string[i];
    }
    string ep;
    for(int i=1; i<=max_size; ++i){
        ep += "_";
    }
    for(int i=1; i<=n; ++i){
        for(int j=n-i-1; j>=0; --j){
            cout << ep;
        }
        for(int j=1; j<=i; ++j){
            cout << fibo_string[j];
        }
        for(int j=i-1; j>=1; --j){
            cout << fibo_string[j];
        }
        for(int j=n-i-1; j>=0; --j){
            cout << ep;
        }
        cout << "\n";
    }
    for(int i=1; i<=n-1; ++i){
        for(int j=1; j<=n; ++j){
            if(j<=i){
                cout << ep;
            }
            else{
                cout << fibo_string[j - i];
            }
        }
        for(int j=n-i-1; j>=1; --j){
            cout << fibo_string[j];
        }
        for(int j=0; j<=i-1; ++j){
            cout << ep;
        }
        cout << "\n";
    }
    return 0;
}


