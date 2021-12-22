#include <iostream>
using namespace std;

class queue{
private:
    int arr[10001];
    int f, b, cnt;
public:
    queue(){
        f = -1;
        b = -1;
        cnt = 0;
    }
    void push(int x);
    int pop();
    int size();
    bool empty();
    int front();
    int back();
};

void queue::push(int x){
    // 경우1: 처음 원소를 넣는 경우
    if(f==-1 && b==-1){
        ++f;
        arr[++b]=x;
    }
    // 경우2: 그 외
    else{
        arr[++b]=x;
    }
    cnt++;
}

int queue::pop(){ // 큐는 앞에 있는 원소 제거하기
    if(cnt==0) return -1;
    else{
        cnt--;
        return arr[f++];
    }
}

int queue::size(){
    return cnt;
}

bool queue::empty(){
    if(cnt==0) return true;
    else return false;
}

int queue::front(){
    if(cnt==0) return -1;
    else return arr[f];
}

int queue::back(){
    if(cnt==0) return -1;
    else return arr[b];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    queue q;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string a; int b;
        cin>>a;
        if(a=="push"){
            cin>>b;
            q.push(b);
        }
        else if(a=="pop"){
            cout<<q.pop()<<"\n";
        }
        else if(a=="size"){
            cout<<q.size()<<"\n";
        }
        else if(a=="empty"){
            cout<<q.empty()<<"\n";
        }
        else if(a=="front"){
            cout<<q.front()<<"\n";
        }
        else{ // a == "back"
            cout<<q.back()<<"\n";
        }
    } // for문 끝
    return 0;
}