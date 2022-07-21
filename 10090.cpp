#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

int n;
int a[1000001] = {0, };
int res[1000001] = {0, };
ll cnt = 0;

void mergeSort(int l, int r){
    if(l==r) return;

    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);

    int i = l, j = mid + 1, idx = l;
    while(i <= mid && j <= r){
        if(a[i] < a[j]) res[idx++] = a[i++];
        else{
            cnt += (j - idx);
            res[idx++] = a[j++];
        }
    }
    
    while(i <= mid){
        res[idx++] = a[i++];
    }
    while(j <= r){
        res[idx++] = a[j++];
    }

    for(i=l; i<=r; i++){ // a 배열에 다시 복원
        a[i] = res[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    mergeSort(0, n-1);

    cout << cnt << endl;
    return 0;
}
