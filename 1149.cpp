#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v; vector<int> t;
    int n, tmp;
    cin>>n;
    for(int i=0; i<3; i++){
      cin>>tmp; v.push_back(tmp);
    }

    for(int i=1; i<n; i++){
      for(int j=0; j<3; j++){
        cin>>tmp;
        if(j==0) t.push_back(min(v[1], v[2])+tmp);
        else if(j==1) t.push_back(min(v[0], v[2])+tmp);
        else t.push_back(min(v[0], v[1])+tmp);
      }
      v = {t.begin(), t.end()}; // 벡터 업데이트
      t.clear();
    }

    cout<<*min_element(v.begin(), v.end())<<endl;
    return 0;
}
