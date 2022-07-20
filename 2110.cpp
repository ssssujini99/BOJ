#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v; int c;

bool possible(int dist){
    int cnt = 1;

    int prev = v[0];

    for(int i=1; i<v.size(); i++){
        if(v[i]-prev >= dist){
            cnt ++;
            prev = v[i];
        }
    }
    if(cnt >= c) return true;
    else return false;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, tmp; cin >> n >> c;

    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int left = 1; int right = v.back() - v.front();
    int res = 1;

    while(left <= right){
        int mid = (left + right) / 2;
        // cout << mid << " " << possible(mid) << endl;

        if(possible(mid)){
            res = max(res, mid); // 갱신
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << res << endl;
    return 0;
}
