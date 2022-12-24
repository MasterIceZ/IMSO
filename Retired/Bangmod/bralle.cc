#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string a = "*_*_*****_***__*_**_*_*****_*****__**_*__******_";
string b = "__*____*_**_*_*_**__*____*_**_****____*_**___*_*";
string c = "_____________*____*_*_*_*_*_*_*_*_*_****_*******";

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for(auto x: s){
        int idx = (x - 'a') * 2;
        cout << a[idx] << a[idx + 1];
    }
    cout << "\n";
    for(auto x: s){
        int idx = (x - 'a') * 2;
        cout << b[idx] << b[idx + 1];
    }
    cout << "\n";
    for(auto x: s){
        int idx = (x - 'a') * 2;
        cout << c[idx] << c[idx + 1];
    }
    return 0;
}

