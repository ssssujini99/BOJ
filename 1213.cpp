#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a[26] = {0, }; int cnt_odd = 0; int odd_idx = -1;
    string s; cin >> s;
    for(int i=0; i<s.size(); i++){
        a[s[i]-'A']++;
    }

    for(int i=0; i<26; i++){
        if(a[i]%2){
            cnt_odd++; // 홀수 개 count 해주기
            odd_idx = i; // 홀수 개인 인덱스값 저장
        }
    }

    if(cnt_odd>1){
        cout << "I\'m Sorry Hansoo\n" << "\n";
        exit(0);
    }

    string res = "";
    for(int i=0; i<26; i++){
        while(a[i]>=2){
            res += i + 'A';
            a[i] -= 2;
        }
    }
    string res2 = res;
    reverse(res2.begin(), res2.end());
    if(odd_idx > -1) res += odd_idx + 'A';
    cout << res + res2 << endl;
    return 0;
}
