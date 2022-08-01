#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;

int func_D(int n){
    return (n*2) % 10000;
}

int func_S(int n){
    if(n==0) return 9999;
    else return n-1;
}

int func_L(int n){
    int d1 = n / 1000; n %= 1000;
    int d2 = n / 100; n %= 100;
    int d3 = n / 10; n %= 10;
    int d4 = n / 1;

    int res = d2*1000 + d3*100 + d4*10 + d1*1;
    return res;
}

int func_R(int n){
    int d1 = n / 1000; n %= 1000;
    int d2 = n / 100; n %= 100;
    int d3 = n / 10; n %= 10;
    int d4 = n / 1;

    int res = d4*1000 + d1*100 + d2*10 + d3*1;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, A, B; cin >> T;
    vector<string> ans;
    while(T--){
        cin >> A >> B;
        
        queue<pair<int, string> > q;
        int ch[100000] = {0, };
        ch[A]=1; q.push(make_pair(A, ""));

        while(!q.empty()){
            int n = q.front().first; string s = q.front().second;
            q.pop();
            // cout << "n:  " << n << endl;
            if(n == B){
                ans.push_back(s);
                break;
            }

            int nn;
            if((nn=func_D(n))>=0 && nn<=10000 && ch[nn]==0){
                ch[nn] = 1;
                q.push(make_pair(nn, s+'D'));
            }
            if((nn=func_S(n))>=0 && nn<=10000 && ch[nn]==0){
                ch[nn] = 1;
                q.push(make_pair(nn, s+'S'));
            }
            if((nn=func_L(n))>=0 && nn<=10000 && ch[nn]==0){
                ch[nn] = 1;
                q.push(make_pair(nn, s+'L'));
            }
            if((nn=func_R(n))>=0 && nn<=10000 && ch[nn]==0){
                ch[nn] = 1;
                q.push(make_pair(nn, s+'R'));
            }
        } // while문 끝
    }

    for(int i=0; i<ans.size(); i++) cout << ans[i] << "\n";

    return 0;
}
