#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int N;
vector<int> rel;
vector<string> ans;
int ch[10] = {0, };
string tmp = "";

void DFS(int idx){ // rel의 idx 값
    if(tmp.size()==N+1){
        ans.push_back(tmp);
    }
    else{
        for(int i=0; i<10; i++){
            if(rel[idx]==0 && !ch[i] && tmp[idx] < i+'0'){
                ch[i] = 1;
                tmp += i + '0';
                DFS(idx+1);
                ch[i] = 0;
                tmp.pop_back();
            }
            if(rel[idx]==1 && !ch[i] && tmp[idx] > i+'0'){
                ch[i] = 1;
                tmp += i + '0';
                DFS(idx+1);
                ch[i] = 0;
                tmp.pop_back();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char c;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> c;
        if(c == '<') rel.push_back(0); // < 이면 0
        else rel.push_back(1); // > 이면 1
    }

    for(int i=0; i<10; i++){
        ch[i] = 1;
        tmp += i + '0';
        DFS(0);
        ch[i] = 0;
        tmp.pop_back();
    }

    sort(ans.begin(), ans.end());
    cout << ans.back() << "\n";
    cout << ans.front() << "\n";
    return 0;
}
