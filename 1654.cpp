#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

typedef long long ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, n, tmp; ll res=0; cin >> k >> n;
    vector<int> v;

    for(int i=0; i<k; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    ll l = 1, r = v.back(), m;
    while(l <= r){
        m = (l+r) / 2;

        int tmp_cnt = 0;
        for(int i=0; i<k; i++) tmp_cnt += (v[i] / m);

        if(tmp_cnt >= n){
            l = m+1;
            res = max(res, m); // n개보다 더 많이 만드는 것도 갱신에 포함
        }
        else r = m-1;
    }

    cout << res << endl;
    return 0;
}
