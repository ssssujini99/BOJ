#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int N, K;
int a[26] = {0, };
int res = 0;
vector<string> v;
vector<int> ind;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    if(K<5){
        cout << 0 << endl;
        exit(0);
    }
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        s = s.substr(4, s.size()-8);
        sort(s.begin(), s.end()); // 정렬
        s.erase(unique(s.begin(), s.end()), s.end()); // 중복 제거
        for(int j=0; j<s.size(); j++){
            a[s[j]-'a']++;
        }
        v.push_back(s);
    }

    a[0] = 0; a[2] = 0; a[8] = 0; a[13] = 0; a[19] = 0;
    s = "";

    for(int i=0; i<26; i++){
        if(a[i]) s += i + 'a';
    } // s -> 한 번씩 등장한 알파벳들 모임

    // cout << s << endl;

    if(K-5 >= s.size()){ // 예외처리 -> 조합 뽑을 때 nCk 에서 k가 더 큰 경우
        cout << N << endl;
        exit(0);
    }

    for(int i=0; i<K-5; i++) ind.push_back(1);
    for(int i=0; i<s.size()-(K-5); i++) ind.push_back(0);
    sort(ind.begin(), ind.end());


    do{
        // 한 조합에 대해서
        int b[26] = {0, };
        b[0] = 1; b[2] = 1; b[8] = 1; b[13] = 1; b[19] = 1;

        for(int i=0; i<ind.size(); i++){
            if(ind[i]) b[s[i]-'a']=1;
        }

        int cnt = 0;
        for(int i=0; i<v.size(); i++){ // 단어 개수
            int state = 0;
            for(int j=0; j<v[i].size(); j++){ // 각 단어에 대해서
                if(b[v[i][j]-'a']==0){
                    state = 1;
                    break;
                }
            }
            if(state==0) cnt++;
        }

        res = max(res, cnt);
        
    }while(next_permutation(ind.begin(), ind.end()));

    cout << res << endl;
    return 0;
}
