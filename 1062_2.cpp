#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int N, K;
int a[26] = {0, };
int res = 0;
int v[51] = {0, };
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
        for(int j=0; j<s.size(); j++){
            v[i] |= (1 << (s[j]-'a'));
            a[s[j]-'a']++;
        }
    }

    a[0] = 0; a[2] = 0; a[8] = 0; a[13] = 0; a[19] = 0;
    s = "";

    for(int i=0; i<26; i++){
        if(a[i]) s += i + 'a';
    } // s -> 한 번씩 등장한 알파벳들 모임


    if(K-5 >= s.size()){ // 예외처리 -> 조합 뽑을 때 nCk 에서 k가 더 큰 경우
        cout << N << endl;
        exit(0);
    }

    for(int i=0; i<K-5; i++) ind.push_back(1);
    for(int i=0; i<s.size()-(K-5); i++) ind.push_back(0);
    sort(ind.begin(), ind.end());


    do{
        // 한 조합에 대해서
        int n = 532741; // 2**0 + 2**2 + 2**8 + 2**13 + 2**19

        for(int i=0; i<ind.size(); i++){
            if(ind[i]) n |= ( 1 << ((s[i]-'a')) );
        }

        int cnt = 0;
        int i;
        for(i=0; i<N; i++){ // 각 단어에 대해서
            if((v[i] & ((1<<26)-1-n)) == 0) cnt++; // 배우지 않는다고 한 알파벳이 단어에 없으면 -> 배울 수 있음
        }
        res = max(res, cnt);
        
    }while(next_permutation(ind.begin(), ind.end()));

    cout << res << endl;
    return 0;
}
