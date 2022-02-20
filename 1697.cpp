#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a[100001]={0, }; int ch[100001]={0, };
  int n, k, dis, w; queue<pair<int, int>> q;
  cin>>n>>k;
  ch[n]=1; q.push({n, 0});

  while(!q.empty()){
    pair<int, int> p = q.front(); q.pop();
    dis = p.second; w = p.first;
    if(p.first == k) break;

    if(2*w<=100000 && ch[2*w]==0){
      ch[2*w]=1; q.push({2*w, dis+1});
    }
    if(w-1>=0 && ch[w-1]==0){
      ch[w-1]=1; q.push({w-1, dis+1});
    }
    if(w+1<=100000 && ch[w+1]==0){
      ch[w+1]=1; q.push({w+1, dis+1});
    }
  }

  cout<<dis;
  return 0;
}
