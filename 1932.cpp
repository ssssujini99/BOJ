#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v; vector<int> t;
    int n, tmp;
    cin>>n;
    cin>>tmp;
    v.push_back(tmp);

    for(int i=1; i<n; i++){
      for(int j=0; j<=i; j++){
        cin>>tmp;
        if(j==0) t.push_back(v[j]+tmp);
        else if(j==i) t.push_back(v[v.size()-1]+tmp);
        else t.push_back(max(v[j-1], v[j])+tmp);
      }
      v = {t.begin(), t.end()}; // 벡터 업데이트
      t.clear();
    }

    cout<<*max_element(v.begin(), v.end())<<endl;
    return 0;
}
