#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v; int x;

bool binarySearch(int l, int r){
    int left = l; int right = r;

    while(left < right){
        int mid = (left + right) / 2;
        if(v[mid] == x) return true;
        else if(v[mid] < x) left = mid + 1;
        else right = mid - 1;
    }

    if(v[left] == x) return true;
    else return false;
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
        cout << binarySearch(0, v.size()-1) << " ";
    }
    return 0;
}
