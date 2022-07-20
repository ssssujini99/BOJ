#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v; int x;

int binarySearch1(int l, int r){
    int left = l; int right = r;

    while(left < right){
        int mid = (left + right) / 2;
        if(v[mid] < x) left = mid + 1;
        else right = mid;
    }

    if(v[left] == x) return left;
    else return -1;
}

int binarySearch2(int l, int r){
    int left = l; int right = r;

    while(left < right){
        int mid = (left + right + 1) / 2;
        if(v[mid] <= x) left = mid;
        else right = mid - 1;
    }

    if(v[left] == x) return left;
    else return -1;
}

int Count(){
    int r2 = binarySearch2(0, v.size()-1);
    int r1 = binarySearch1(0, v.size()-1);

    if(r2 == -1 && r1 == -1) return 0;
    else return r2 - r1 + 1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, tmp; cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        x = tmp;
        cout << Count() << " ";
    }
    return 0;
}
