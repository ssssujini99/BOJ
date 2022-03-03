#include <bits/stdc++.h>
using namespace std;

int n;

void func(int x, int y, int k){
  if(x%3==1 && y%3==1) cout<<" ";
  else if(k==1) cout<<"*";
  else func(x/3, y/3, k/3);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin>>n;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      func(i, j, n);
    }
    cout<<"\n";
  }
}
