#include <bits/stdc++.h>
using namespace std;

long long d[91]={0, };

long long func(int num){
  if(d[num]) return d[num];

  else return d[num]=func(num-1)+func(num-2); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    d[1]=1; d[2]=1; // 초기 조건 세팅
    int n;
    cin>>n;
    cout<<func(n)<<endl;
    return 0;
}
