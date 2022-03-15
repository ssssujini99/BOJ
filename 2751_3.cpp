#include <bits/stdc++.h>
using namespace std;

int a[1000001]={0, };

void mergeSort(int left, int right){
  if(left>=right) return;

  int mid = (left + right) / 2;

  // divide
  mergeSort(left, mid);
  mergeSort(mid+1, right);

  // merge
  vector<int> tmp; int i = left, j = mid+1;
  while(i<=mid && j<=right){
    if(a[i]<a[j]) tmp.push_back(a[i++]);
    else tmp.push_back(a[j++]);
  }
  while(i<=mid) tmp.push_back(a[i++]);
  while(j<=right) tmp.push_back(a[j++]);

  // tmp에 있는 거 다시 a배열로 복원시키기
  for(int k=0, i=left; k<tmp.size(); k++) a[i++]=tmp[k];
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];

  mergeSort(0, n-1);

  for(int i=0; i<n; i++) cout<<a[i]<<"\n";
  
  return 0;
}
