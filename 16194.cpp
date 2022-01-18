#include <iostream>
using namespace std;

int d[1001]={0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp, res, cnt=0;
    cin>>n;
    cin>>tmp;
    d[1]=tmp;

    for(int i=2; i<=n; i++){
      cin>>tmp;
      d[i]=tmp;
      for(int j=i-1; j>=i/2; j--){
        d[i]=min(d[i], d[j]+d[i-j]);
      }
    }

    cout<<d[n]<<endl;
    
    return 0;
}