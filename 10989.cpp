#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, tmp; cin>>n;
  int a[10001]={0, };
  
  for(int i=0; i<n; i++){
    cin>>tmp; a[tmp]+=1;
  }

  for(int i=1; i<=10000; i++){
    for(int j=0; j<a[i]; j++){
      cout<<i<<"\n";
    }
  }
  return 0;
}
