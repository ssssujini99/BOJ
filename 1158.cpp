#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> q;
    int n, k, tmp, j=1;

    cin>>n>>k;

    for(int i=1; i<=n; i++){
        q.push(i);
    }
    cout<<"<";
    while(j<n){
        for(int i=0; i<k-1; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        } // 다시 큐에 넣어주는 부분
        cout<<q.front()<<", "; // k번째는 출력 후
        q.pop(); // 큐에서 pop 하기
        j++;
    }
    cout<<q.front()<<">"<<endl;
    return 0;
}