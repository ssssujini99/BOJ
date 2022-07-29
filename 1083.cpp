#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v;
    int N, S, tmp; cin >> N;

    for(int i=0; i<N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> S;

    vector<int> vv = v;
    sort(vv.begin(), vv.end());


    for(int i=0; i<v.size() && S>0; i++){
        if(v[i] == vv[vv.size()-i]) continue; // 해당 내림차순 배열과 동일하다면 -> continue

        int j = i+1, cnt = S, max_idx = i, max_el = v[i];

        for(; j<v.size() && cnt>0; j++, cnt--){ // i번째 이후에 가장 큰 원소 찾기
            if(max_el < v[j]){
                max_el = v[j];
                max_idx = j;
            }
        }

        S -= (max_idx - i);
        for(; max_idx>=i+1; max_idx--){
            swap(v[max_idx], v[max_idx-1]);
        }
    }


    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
    return 0;
}
