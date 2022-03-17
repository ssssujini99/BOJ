#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin>>n;
  vector<ll> v; vector<ll> ori;

  for(int i=0; i<n; i++){
    int tmp; cin>>tmp; v.push_back(tmp); ori.push_back(tmp);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(),v.end()), v.end()); // 벡터 중복 원소 제거

  unordered_map<ll, ll> um;
  for(int i=0; i<v.size(); i++) um[v[i]]=i; // 키: 해당원소, 값: 순위

  for(int i=0; i<ori.size(); i++) cout<<um[ori[i]]<<" ";
  return 0;
}
