#include <iostream>
using namespace std;

class stack{
private:
    int arr[10001];
    int idx; // 현재 인덱스가 top번까지 저장되어 있음
public:
    stack(){
        idx = -1;
    }
    void push(int x);
    int pop();
    int size();
    bool empty();
    int top();
};

void stack::push(int x){
    arr[++idx]=x;
}

int stack::pop(){
    if(idx==-1) return -1;
    return arr[idx--];
}

int stack::size(){
    return idx+1;
}

bool stack::empty(){
    if(idx==-1) return true;
    else return false;
}

int stack::top(){
    if(idx==-1) return -1;
    else return arr[idx];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack s;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string a; int b;
        cin>>a;
        if(a=="push"){
            cin>>b;
            s.push(b);
        }
        else if(a=="pop"){
            cout<<s.pop()<<"\n";
        }
        else if(a=="size"){
            cout<<s.size()<<"\n";
        }
        else if(a=="empty"){
            cout<<s.empty()<<"\n";
        }
        else{ // a == "top"
            cout<<s.top()<<"\n";
        }
    } // for문 끝
    return 0;
}