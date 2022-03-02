#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int, int>> v; int rank[50]={0, };
  int n; cin>>n;

  for(int i=0; i<n; i++){
    int t1, t2; cin>>t1>>t2;
    v.push_back({t1, t2});
  }

  for(int i=0; i<n; i++){
    int rank = 1; // 자신이 1등이라 가정
    for(int j=0; j<n; j++){
      if(j!=i && v[i].first < v[j].first && v[i].second < v[j].second) rank++;
    }
    cout<<rank<<" ";
  }
  
  
  return 0;
}
