#include <iostream>
using namespace std;

int a[1001]={0, };
int d[1001]={0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp, res;
    cin>>n;
    cin>>tmp;
    a[1]=tmp;
    d[1]=1;
    res=1;

    for(int i=2; i<=n; i++){
      cin>>tmp;
      a[i]=tmp;
      d[i]=1;

      for(int j=i-1; j>=1; j--){
        if(a[j]<a[i]){
          d[i]=max(d[i], d[j]+1);
        }
      }

      res=max(res, d[i]);
    }

    cout<<res<<endl;
    return 0;
}