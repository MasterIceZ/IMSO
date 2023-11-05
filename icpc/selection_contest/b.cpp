#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e6+5;
const int mod=1e9+7;

int n;
int a[N];
int mn[N],c2[N],c1=0,q[N][5];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i=2;i<=n;i++)mn[i]=1e9;
  for (int i=1;i<=n;i++){
    int o;
    cin >> o;
    q[i][0]=o;
    if (o==1){
      cin >> q[i][1];
      c1++;
    }
    if (o==2){
      cin >> q[i][1] >> q[i][2];
      c2[q[i][1]]++;
    }
  }
  mn[1]=c1+c2[1];
  for (int i=1;i<=n;i++){
    if (q[i][0]==1){
      c1--;
      mn[q[i][1]]=min(mn[q[i][1]],c1+c2[q[i][1]]);
    } 
    if (q[i][0]==2){
      int v=mn[q[i][1]]-c1-c2[q[i][1]];
      if (mn[q[i][1]]==1e9) v=1e9;
      c2[q[i][1]]--;
      v+=c1+c2[q[i][2]];
      mn[q[i][2]]=min(mn[q[i][2]],v);
      // cout << i << ' ' << v << '\n';
    }
  }
  for (int i=1;i<=n;i++) {
    if (mn[i]==1e9) cout << "-1 ";
    else cout << mn[i] << ' ';
  }
}