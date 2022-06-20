#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int n, t1, t2, tmp;
    cin>>n;
    cin>>t1>>t2;
    cout<<t1<<"\n";
    cout<<min(t1, t2)<<"\n";

    pq1.push(min(t1, t2)); pq2.push(max(t1, t2));

    for(int i=3; i<=n; i++){
        cin>>tmp;
        if(tmp < pq2.top()) pq1.push(tmp);
        else pq2.push(tmp);

        // 맞춰주는 과정 -> 차이가 최대 1 이하가 될 때까지
        while(pq1.size()-1 > pq2.size()){
            pq2.push(pq1.top());
            pq1.pop();
        }
        while(pq2.size()-1 > pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }

        // 출력과정
        if(pq1.size()==pq2.size()) cout<<pq1.top()<<"\n";
        else if(pq1.size() > pq2.size()) cout<<pq1.top()<<"\n";
        else cout<<pq2.top()<<"\n";
    }
    
    return 0;
}
