#include <bits/stdc++.h>
using namespace std;

struct cmp{
  bool operator()(pair<int, int>a, pair<int, int>b){
    if(a.first==b.first) return a.second > b.second;
    else return a.first > b.first;
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin>>n;
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  vector<pair<int, int>> v;

  for(int i=0; i<n; i++){
    int t1, t2; cin>>t1>>t2;
    pq.push({t1, t2});
  }

  while(!pq.empty()){
    cout<<pq.top().first<<" "<<pq.top().second<<"\n";
    pq.pop();
  }
  return 0;
}
