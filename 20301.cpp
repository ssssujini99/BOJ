#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  queue<int> q; stack<int> s;
  int n, k, m; cin >> n >> k >> m;

  for(int i=0; i<n; i++) q.push(i+1);


  int cnt = 0;
  while(!q.empty()){
      if(cnt == m){
          // 원의 방향 바꾸기 -> 스택 이용
          while(!q.empty()){
              s.push(q.front()); q.pop();
          }

          while(!s.empty()){
              q.push(s.top()); s.pop();
          }

          cnt = 0;
      }

      for(int i=0; i<k-1; i++){
          q.push(q.front());
          q.pop();
      }

      // 출력
      cout << q.front() << "\n";
      q.pop();
      cnt++;
  }
  return 0;
}
