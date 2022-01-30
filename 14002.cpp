#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v[1001]; vector<int> a;
    int n, tmp, j, max_size;
    cin>>n;

    for(int i=0; i<n; i++){
      cin>>tmp;
      a.push_back(tmp);
      max_size=1;
      for(int j=i-1; j>=0; j--){
        if(a[j]<tmp && max_size<v[j].size()+1){
          v[i].clear();
          v[i] = v[j];
          max_size = v[j].size()+1;
        }
      }
      v[i].push_back(tmp);
    }

    int max_idx=0;
    for(int i=1; i<n; i++){
      if(v[i].size() > v[max_idx].size()) max_idx=i;
    }
    cout<<v[max_idx].size()<<endl;
    for(int i=0; i<v[max_idx].size(); i++){
      cout<<v[max_idx][i]<<" ";
    }

    return 0;
}
