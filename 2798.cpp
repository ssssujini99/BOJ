#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a[100]={0, }; int n, m;
  cin>>n>>m;

  for(int i=0; i<n; i++) cin>>a[i];
  int res = a[0]+a[1]+a[2];

  for(int i=3; i<n; i++){
    for(int j=i-1; j>=1; j--){
      for(int k=j-1; k>=0; k--){
        int t1=a[i], t2=a[j], t3=a[k], sum=t1+t2+t3;
        if(sum<=m && min(abs(res-m), abs(sum-m))==abs(sum-m)){
          res = sum;
        }
      }
    }
  }
  
  cout<<res<<endl;
  return 0;
}
