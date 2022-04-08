#include <iostream>
#include <cmath>
using namespace std;

int n, total=0;
int row[15];

bool check(int t){
    for(int i=0; i<t; i++){
        if(row[i]==row[t] || abs(row[t]-row[i])==t-i) return false; // 같은 라인에 있거나 || 대각선에서 겹치는 경우
    }
    return true;
}

void NQueen(int k){
    if(k==n) total++;
    else{
        for(int i=0; i<n; i++){
            row[k]=i;
            if(check(k)) NQueen(k+1);
        }
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin>>n;
  NQueen(0);
  cout<<total<<"\n";
}
