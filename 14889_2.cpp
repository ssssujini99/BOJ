#include <bits/stdc++.h>
using namespace std;

int n;
int res[21]={0, };
int a[20][20]={0, };
vector<int> v;

int total = 0;
int gap = INT_MAX;

void dfs(int cnt){
    if(cnt==n/2 + 1){
        vector<int> tmp = v;
        for(int i=1; i<=n/2; i++){
            tmp.erase(remove(tmp.begin(), tmp.end(), res[i]), tmp.end()); // 원소 지우기
        }

        int sum = 0, sum2 = 0;

        for(int i=1; i<=n/2; i++){
            for(int j=1; j<=n/2; j++){
                sum += a[res[i]][res[j]];
                sum2 += a[tmp[i-1]][tmp[j-1]];
            }
        }
        
        // 최솟값 갱신시키기
        gap = min(gap, abs(sum-sum2));
    }
    else{
        for(int i=res[cnt-1]+1; i<n; i++){
            res[cnt]=i;
            dfs(cnt+1);
            res[cnt]=0;
        }
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cin>>a[i][j]; // 2차원 배열 입력받기
          total += a[i][j];
      }
      v.emplace_back(i);
  }
  res[0]=-1;
  res[1]=0;
  dfs(2);

  cout<<gap<<"\n";
  return 0;
}
