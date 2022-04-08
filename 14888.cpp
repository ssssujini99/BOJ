#include <iostream>
#include <climits>
using namespace std;

int n;
int a[11]={0, };
int op[4]={0, };
int res[10]={0, };
long long int max_sum = LLONG_MIN;
long long int min_sum = LLONG_MAX;

void dfs(int idx){
    if(idx==n-1){
        for(int i=0; i<n-1; i++){
            if(res[i]==0) return;
        }

        long long int sum=a[0];
        for(int i=0; i<n-1; i++){
            if(res[i]==1) sum += a[i+1];
            if(res[i]==2) sum -= a[i+1];
            if(res[i]==3) sum *= a[i+1];
            if(res[i]==4) sum /= a[i+1];
        }
        // 최대값, 최소값 갱신시키기
        max_sum = max(max_sum, sum);
        min_sum = min(min_sum, sum);
    }
    else{
        for(int i=0; i<4; i++){
            if(op[i]>0){
                res[idx]=i+1;
                op[i]-=1;
                dfs(idx+1);
                op[i]+=1; // 복원
                res[idx]=0; // 복원
            }
        }
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tmp;
  cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<4; i++) cin>>op[i];

  dfs(0);

  cout<<max_sum<<"\n"<<min_sum<<"\n";
  return 0;
}
