#include<bits/stdc++.h>

using namespace std;

const double C = sqrt(2.0);

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  long long w;
  cin >> n >> w;
  multiset<long long> msl,msr;
  map<pair<long long,long long>,bool> seen;
  cout << fixed << setprecision(15);
  for(int i=0;i<n;i++){
    long long x,y;
    cin >> x >> y;
    if(!seen[{x,y}]){
      msl.emplace(x-y);
      msr.emplace(x+y);
      seen[{x,y}]=true;
    }else{
      msl.erase(msl.find(x-y));
      msr.erase(msr.find(x+y));
      seen[{x,y}]=false;
    }
    if(msl.empty()){
      cout << 0.0 << "\n";
    }else{
      double l=max(0LL,*msl.begin());
      double r=min(w,*msr.rbegin());
      cout << (r-l)*C << "\n";
    }
  }
}