#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000009;
long long a[1000001]={0, };

void func(void){
    a[1]=1; a[2]=2; a[3]=4;
    
    for(int i=4; i<=1000000; i++){
        a[i]=(a[i-1]+a[i-2]+a[i-3])%MOD;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    func();
    int t, n;
    cin>>t;
    for(int i=0; i<t; i++){
      cin>>n;
      cout<<a[n]<<"\n";
    }
    
    return 0;
}
