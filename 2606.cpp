#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c, t1, t2; cin>>n>>c;
    vector<int> v[n+1]; queue<int> q;
    int ch[101]={0, };

    for(int i=0; i<c; i++){
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }

    ch[1]=1;
    q.push(1);

    // bfs 수행 -> 연결된 것들 모두 찾기
    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(int i=0; i<v[top].size(); i++){
            if(!ch[v[top][i]]){
                ch[v[top][i]]=1;
                q.push(v[top][i]);
            }
        }
    }

    // 연결된 컴퓨터 개수 세기
    int res = 0;
    for(int i=2; i<=n; i++){
        if(ch[i]) res++;
    }

    cout<<res<<endl;
    return 0;
}
