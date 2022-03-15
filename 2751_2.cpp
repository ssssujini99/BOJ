#include <bits/stdc++.h>
using namespace std;

int a[1000001]={0, };

void mergeSort(int l, int r){
  if(l>=r) return;

  int mid = (l + r) / 2;

  // divide
  mergeSort(l, mid);
  mergeSort(mid+1, r);

  // merge
  vector<int> tmp;
  int i=l, j=mid+1;
  while(i<=mid && j<=r){
    if(a[i]<a[j]) tmp.push_back(a[i++]);
    else tmp.push_back(a[j++]);
  }
  while(i<=mid) tmp.push_back(a[i++]);
  while(j<=r) tmp.push_back(a[j++]);

  for(int k=0, i=l; k<tmp.size(); k++){
    a[i++]=tmp[k];
  }
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
