#include <bits/stdc++.h>
using namespace std;

vector<int> z_algo(vector<int> a){
  int n=a.size();
  vector<int> z(n);
  z[0]=n;
  for(int i=1,l=0,r=1;i<n;i++){
    if(i<r)z[i]=min(r-i,z[i-l]);
    while(i+z[i]<n&&a[z[i]]==a[i+z[i]])z[i]++;
    if(i+z[i]>r)l=i,r=i+z[i];
  }
  return z;
}

int main (){
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> s(n), t(m);
  for(auto &x:s){
    cin >> x;
  }
  for(auto &x:t){
    cin >> x;
  }
  for(int i=0;i<n;i++){
    s.emplace_back(s[i]);
  }
  auto ok = [&](vector<int> t) {
    for(int i=0;i<2*n;i++)t.emplace_back(s[i]);
    auto z=z_algo(t);
    for(int i=m;i<m+2*n;i++){
      if(z[i]>=m){
        return true;
      }
    }
    return false;
  };

  if(ok(t)) {
    cout << 1;
    return 0;
  }
  reverse(t.begin(), t.end());
  if(ok(t)) {
    cout << 1;
    return 0;
  }
  cout << 0;
}