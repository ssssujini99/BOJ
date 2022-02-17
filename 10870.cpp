#include <bits/stdc++.h>
 using namespace std;

 long long a[21]={0, };

 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

     a[0]=0; a[1]=1;
     int n; cin>>n;
     for(int i=2; i<=n; i++){
       a[i]=a[i-1]+a[i-2];
     }
     cout<<a[n]<<endl;
     return 0;
 }
