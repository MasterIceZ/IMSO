#include<bits/stdc++.h>

#include "Shokun.h"

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int sum = a + b;
  if(sum % 4 == 0){
    cout << "Four\n";
  }
  else if(sum % 2 == 0){
    cout << "Two\n";
  }
  return 0;
}