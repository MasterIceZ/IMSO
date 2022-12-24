#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    map<string, string> a;
    vector<string> in = {"--.- .. -..- -..- .- .-. ---.. ----. -----", "-.- .. .-.. .-. -. .--. -.-. .-. -..", "--. --- -- ..-. / .-- .. .-. -.. -.-- --- .--. -- -..", "-. ... -- .... --.. .--. ..-. / .--- ... ...- .-.. ... -.-- .--- .--. -- / ...-- .---- ...-- ....-", ".. -- --- -... .-. - -.. --- -.-- ..- / ..--- ...-- --...", "...-- ..... ..--- ...-- ...-- -.... --... -.... . .-. .- ...- .--. --.. .-."};
    vector<string> out = {"PUZZLE789", "JUKEBOXES", "FIND QUESTIONS", "BANGMOD HACKATHON 2023", "UNIVERSITY 126", "24122565WELCOME"};
    int n = 6;
    for(int i=1; i<=n; ++i){
        stringstream ss_1(in[i - 1]);
        vector<string> aa;
        string t;
        while(getline(ss_1, t, ' ')){
            aa.emplace_back(t);
        }
        for(int k=0; k<aa.size(); ++k){
            a[aa[k]] = out[i - 1][k];
        }
    }
    string s, t;
    getline(cin, s);
    stringstream ss(s);
    while(getline(ss, t, ' ')){
        cout << a[t];
    }
    return 0;
}



