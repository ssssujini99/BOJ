#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b){
  if(a.first!=b.first){
    return a.first<b.first;
  }
  else return a.second<b.second;
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin>>n;
  vector<pair<int, int>> v;

  for(int i=0; i<n; i++){
    int t1, t2; cin>>t1>>t2;
    v.push_back({t1, t2});
  }

  sort(v.begin(), v.end(), compare);

  for(int i=0; i<n; i++){
    cout<<v[i].first<<" "<<v[i].second<<"\n";
  }

  return 0;
}
