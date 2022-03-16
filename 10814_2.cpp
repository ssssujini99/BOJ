#include <bits/stdc++.h>
  using namespace std;

  struct cmp{
    bool operator()(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b){
      if(a.first.first!=b.first.first){
        return a.first.first > b.first.first; // 나이가 다르면 나이 증가순으로
      }
      else{ // 나이가 같으면 -> 가입 순서대로
        return a.second > b.second;
      }
    }
  };


  int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    priority_queue<pair<pair<int, string>, int>, vector<pair<pair<int, string>, int>>, cmp> pq;
    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
      int age; string str; cin>>age>>str;
      pq.push({{age, str}, i});
    }

    while(!pq.empty()){
      cout<<pq.top().first.first<<" "<<pq.top().first.second<<"\n";
      pq.pop();
    }
    return 0;
  }
