#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, a, b, c;
vector<int> v[101]; int ch[101]={0, };

void DFS(int N, int L){
    if(N==b){
        cout<<L<<endl;
        exit(0);
    }
    else{
        for(int i=0; i<v[N].size(); i++){
            if(!ch[v[N][i]]){
                ch[v[N][i]]=1; // 방문 처리
                DFS(v[N][i], L+1); // 이후 DFS 수행
                ch[v[N][i]]=0; // 복원
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>a>>b>>c;
    int t1, t2;

    for(int i=0; i<c; i++){
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }

    ch[a]=1;
    DFS(a, 0);
    cout<<-1<<endl;
    return 0;
}
