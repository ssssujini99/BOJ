#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ch[1000001]={0, };
    queue<pair<int, int> > q;

    int f, s, g, u, d; cin>>f>>s>>g>>u>>d;

    // s층에서 -> g층으로 이동하기
    ch[s]=1;
    q.push(make_pair(s, 0));

    while(!q.empty()){
        int height = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(height==g){
            cout<<cnt<<endl;
            exit(0);
        }

        if(height+u<=f && !ch[height+u]){
            ch[height+u]=1;
            q.push(make_pair(height+u, cnt+1));
        }
        if(height-d>=1 && !ch[height-d]){
            ch[height-d]=1;
            q.push(make_pair(height-d, cnt+1));
        }
    }

    cout<<"use the stairs"<<endl;
    return 0;
}
