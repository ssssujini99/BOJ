#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> a, b, res;
    int n, tmp;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>tmp;
        a.push(tmp);
    }

    res.push(-1);
    b.push(a.top());
    a.pop();

    while(res.size()<n){
        if(a.top()>b.top()){ // 경우 1 -> b 스택 빼는 작업 해야함
            while(!b.empty() && a.top()>b.top()){
                b.pop();
            }
            if(!b.empty()){
                res.push(b.top());
                b.push(a.top());
                a.pop();
            }
            else{ // b.empty() 일 때
                res.push(-1);
                b.push(a.top());
                a.pop();
            }
        }
        else { // 경우 2 : a.top() < b.top()
            res.push(b.top());
            b.push(a.top());
            a.pop();
        }
    }

    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    return 0;
}