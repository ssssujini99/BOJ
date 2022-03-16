#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void mergeSort(int left, int right){
  if(left>=right) return;

  int mid = (left + right)/2;
  mergeSort(left, mid);
  mergeSort(mid+1, right);

  vector<int> tmp;
  int i = left, j = mid+1;
  while(i<=mid && j<=right){
    if(v[i]>v[j]) tmp.push_back(v[i++]);
    else tmp.push_back(v[j++]);
  }
  while(i<=mid) tmp.push_back(v[i++]);
  while(j<=right) tmp.push_back(v[j++]);

  for(int i=0, k=left; i<tmp.size(); i++){
    v[k++]=tmp[i];
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string str; cin>>str;

  for(int i=0; i<str.size(); i++){
    v.push_back(int(str[i]-'0'));
  }

  mergeSort(0, v.size()-1);

  for(int i=0; i<v.size(); i++) cout<<v[i];

  return 0;
}
