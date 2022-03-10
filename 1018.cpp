#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a[51][51]={0 };
  int c[8][8]={
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1}
  };
  int d[8][8]={
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0}
  };
  
  int n, m, res=63;
  cin>>n>>m;
  
  for(int i=0; i<n; i++){
    string str; cin>>str;
    for(int j=0; j<str.size(); j++){
      if(str[j]=='W') a[i][j]=0;
      else a[i][j]=1;
    }
  } // 입력끝

  int start=-1;
  for(int i=0; i<=n-8; i++){
    for(int j=0; j<=m-8; j++){
      start = a[i][j];
      int tmp=0;
      if(start==1){
        // c랑 비교
        for(int k=0; k<8; k++){
          for(int l=0; l<8; l++){
            if(a[i+k][j+l]!=c[k][l]) tmp++;
          }
        }
      }
      else{
        // d랑 비교
        for(int k=0; k<8; k++){
          for(int l=0; l<8; l++){
            if(a[i+k][j+l]!=d[k][l]) tmp++;
          }
        }
      }
      // 비교 끝
      tmp=min(tmp, 64-tmp);
      res=min(res, tmp);
    }
  }

  cout<<res<<endl;
  return 0;
}
