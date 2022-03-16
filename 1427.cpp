#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  priority_queue<int, vector<int>, less<int>> pq; string str;
  cin>>str;

  for(int i=0; i<str.size(); i++){
    pq.push(int(str[i]-'0'));
  }

  while(!pq.empty()){
    cout<<pq.top();
    pq.pop();
  }

  return 0;
}
