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

    int n, tmp; vector<ll> v;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    int l = 0; int r = v.size()-1;
    ll res = 2147483647; ll dis;
    ll res_r = v[r]; ll res_l = v[l];

    while(l<r){
        dis = v[r] + v[l];
        if(abs(dis) < res){
            res = abs(dis);
            res_r = v[r]; res_l = v[l];
        }

        if(res == 0) break;
        if(dis > 0) r--;
        else l++;
    }
    cout << res_l << " " << res_r << endl;
    return 0;
}
