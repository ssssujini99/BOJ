#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> res;
    int n, tmp, j, max_size;
    int a[1001]={0, };
    int cnt[1001]={0, };
    int idx[1001]={0, };
    cin>>n;

    for(int i=1; i<=n; i++){
      cin>>tmp;
      a[i]=tmp;
      idx[i]=0;
      cnt[i]=1;
      max_size=1;
      for(int j=i-1; j>=1; j--){
        if(a[j]<tmp && max_size<cnt[j]+1){
          idx[i]=j;
          max_size = cnt[j]+1;
          cnt[i]=cnt[j]+1;
        }
      }
    }

    int max_idx=1;
    for(int i=2; i<=n; i++){
      if(cnt[max_idx] < cnt[i]) max_idx=i;
    }
    cout<<cnt[max_idx]<<endl;

    while(max_idx>0){
      res.push_back(a[max_idx]);
      max_idx = idx[max_idx];
      if(max_idx==0) break;
    }

    for(int i=res.size()-1; i>=0; i--) cout<<res[i]<<" ";
    return 0;
}
