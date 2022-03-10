#include <bits/stdc++.h>
using namespace std;

int a[1000001];

void func(int l, int r){
  if(l>=r) return;

  int mid = (l+r)/2;
  func(l, mid);
  func(mid+1, r);

  vector<int> tmp;
  int i=l, j=mid+1;
  while(i<=mid && j<=r){
    if(a[i]<a[j]) tmp.push_back(a[i++]);
    else tmp.push_back(a[j++]);
  }
  while(i<=mid) tmp.push_back(a[i++]);
  while(j<=r) tmp.push_back(a[j++]);

  int k=l;
  for(int j=0; j<tmp.size(); j++){
    a[k++]=tmp[j];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];

  func(0, n-1);

  for(int i=0; i<n; i++) cout<<a[i]<<"\n";
  return 0;
}
