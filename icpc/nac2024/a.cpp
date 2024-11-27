#include <bits/stdc++.h>
using namespace std;

const int N=55;
int a[N],b[N];

vector<pair<int,int>> v,v2;

int cal (int p,int na,int nb){
  return max(v2[p].first+na,v2[p].second+nb);
}

int main (){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,mn=1e9;;
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i] >> b[i];
  for (int i=0;i<1<<(n/2);i++){
    int sa=0,sb=0;
    for (int j=0;j<n/2;j++){
      if (i&1<<j){
        sa+=a[j];
      }
      else{
        sb+=b[j];
      }
    }
    v.emplace_back(sa,sb);
  }
  sort(v.begin(),v.end());
  v2.emplace_back(0,1e9);
  for (auto [na,nb]:v){
    if (v2[v2.size()-1].second > nb) v2.emplace_back(na,nb);
  }
  v2.emplace_back(1e9,0);
  for (auto [na,nb]:v2) cout << " => " << na << ' ' << nb << '\n';
  for (int i=0;i<1<<(n-n/2);i++){
    int sa=0,sb=0;
    for (int j=1;j<(n-n/2);j++){
      if (i&1<<j) sa+=a[j+n/2];
      else sb+=b[j+n/2];
    }
    int l=0,r=v2.size()-1,mid;
    while (l<=r){
      mid=(l+r)/2;
      if (cal(mid - 1, sa, sb) > cal(mid, sa, sb) && cal(mid + 1, sa, sb) > cal(mid, sa, sb)){
        mn=min(mn,cal(mid,sa,sb));
        cout << " --> " << sa << ' ' << sb << ' ' << cal(mid,sa,sb) << '\n';
        break;
      }
      if (cal(mid - 1, sa, sb) > cal(mid, sa, sb) && cal(mid + 1, sa, sb) < cal(mid, sa, sb)){
        l=mid+1;
      }
      else r=mid-1;
    }
  }
  cout << mn;
}