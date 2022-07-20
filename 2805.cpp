#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<long long> v; int n; long long m, tmp;

bool possible(int height){
    long long sum = 0;
    for(int i=0; i<n; i++){
        if(v[i]-height > 0) sum += (v[i] - height);
    }
    if(sum >= m) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    long long left = 0; long long right = v.back();
    long long res = 0;

    while(left <= right){
        long long mid = (left + right) / 2;

        if(possible(mid)){
            res = max(res, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << res << endl;
    return 0;
}
