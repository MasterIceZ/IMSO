#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll pw[20];

int ask(ll x){
  cout << "query " << x << endl;
  int res=0;
  cin >> res;
  return res;
}

void answer(ll x){
  cout << "answer " << x << endl;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  pw[0]=1;
  for(int i=1;i<18;i++)pw[i]=pw[i-1]*10;
  ll ans=0;
  int z=ask(0);
  for(int i=0;i<18;i++){
    int l=1,r=10;
    while(l<r){
      int m=(l+r)/2;
      if(ask(m*pw[i])<=z)r=m;
      else l=m+1;
    }
    ans+=(10-l)*pw[i];
  }
  answer(ans);
}