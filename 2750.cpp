#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; vector<int> v;
  cin>>n;
  for(int i=0; i<n; i++){
    int tmp; cin>>tmp; v.push_back(tmp);
  }

  for(int i=0; i<v.size()-1; i++){
    for(int j=i+1; j<v.size(); j++){
      if(v[i]>v[j]) swap(v[i], v[j]);
    }
  } // i가 끝날 때마다 i의 자리가 구해 짐 -> 방향으로

  for(int i=0; i<v.size(); i++) cout<<v[i]<<"\n";
  return 0;
}
