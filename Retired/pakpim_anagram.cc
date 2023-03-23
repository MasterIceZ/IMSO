#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s,t;
const ll PRIME = 2003ll;
const ll MOD = 1e9 + 7;
ll a[2005][255],b[2005][255], pakpim[255];
//map<vector<ll>,bool> mp;
map<ll, bool> mp;
bool f(int mid){
    for (ll j=1;j+mid-1<=t.size();j++){
        //vector<ll> v;
        //for (ll k='A';k<='Z';k++) v.emplace_back(b[j+mid-1][k]-b[j-1][k]);
		ll v = 0ll;
        //for (ll k='A';k<='Z';k++) v = (v * PRIME + (b[j + mid - 1][k] - b[j - 1][k])) % MOD;
	    for (ll k='A';k<='Z';k++) v = v + (pakpim[k - 'A'] * (b[j + mid - 1][k] - b[j - 1][k]));
        if (mp[v]) return 1;
    }
    return 0;
}
int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    for(ll i=1;i<=s.size();i++){
        a[i][s[i-1]]++;
        for (ll j='A';j<='Z';j++) a[i][j]+=a[i-1][j];
    }
    for(ll i=1;i<=t.size();i++){
        b[i][t[i-1]]++;
        for (ll j='A';j<='Z';j++) b[i][j]+=b[i-1][j];
    }
	pakpim[0] = 1ll;
	for(ll i=1; i<=27; ++i){
		pakpim[i] = (pakpim[i - 1] * PRIME) % MOD;
	}
	for(ll i=1; i<=s.size(); ++i){
		for (ll j=i; j<=s.size(); j++){
	        //vector<ll> v;
	        //for (ll k='A';k<='Z';k++) v.emplace_back(a[j][k]-a[i - 1][k]);
			ll v = 0ll;
	        for (ll k='A';k<='Z';k++) v = v + (pakpim[k - 'A'] * (a[j][k] - a[i - 1][k]));
	        mp[v]=1;
	    }
	}
    ll l=1,r=min(t.size(),s.size()),mid,mx=0;
    while (l<r){
        mid=(l+r+1)/2;
        if (f(mid)){
            l=mid;
        }
        else r=mid-1;
    }
    cout << l;
}
