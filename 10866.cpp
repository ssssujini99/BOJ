#include <iostream>
using namespace std;

class deque{
private:
    int arr[10001];
    int brr[10001];
    int a_front, a_back, b_front, b_back, a_cnt, b_cnt;
public:
    deque(){
        a_front = -1;
        a_back = -1;
        b_front = -1;
        b_back = -1;
        a_cnt = 0;
        b_cnt = 0;
    }
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    int size();
    bool empty();
    int front();
    int back();
};

void deque::push_front(int x){
    // 경우1: arr배열에 처음으로 넣는 경우
    if(a_front==-1 && a_back==-1){
        (a_back)++;
        arr[++(a_front)]=x;
    }
    // 경우2: 그 외
    else{
        arr[++(a_front)]=x;
    }
    (a_cnt)++;
}

void deque::push_back(int x){
    // 경우1: brr배열에 처음으로 넣는 경우
    if(b_front==-1 && b_back==-1){
        (b_front)++;
        brr[++(b_back)]=x;
    }
    // 경우2: 그 외
    else{
        brr[++(b_back)]=x;
    }
    (b_cnt)++;
}

int deque::pop_front(){ // 덱의 가장 앞에 있는 수 제거
    // 경우1: 가장 앞에 있는 수가 arr배열에 있는 경우 // arr배열에 수가 있는 경우
    if(a_cnt){
        (a_cnt)--;
        return arr[(a_front)--];
    }
    // 경우2: 가장 앞에 있는 수가 brr배열에 있는 경우
    else if(b_cnt){
        (b_cnt)--;
        return brr[(b_front)++];
    }
    // 경우3: 덱이 비어있는 경우
    else{
        return -1;
    }
}

int deque::pop_back(){ // 덱의 가장 뒤에 있는 수 제거
    // 경우1: brr배열에 수가 있는 경우
    if(b_cnt){
        (b_cnt)--;
        return brr[(b_back)--];
    }
    // 경우2: arr배열에 수가 있는 경우
    else if(a_cnt){
        (a_cnt)--;
        return arr[(a_back)++];
    }
    // 경우3: 덱이 비어있는 경우
    else{
        return -1;
    }
}

int deque::size(){
    return (a_cnt)+(b_cnt);
}

bool deque::empty(){
    if(size()==0) return true;
    else return false;
}

int deque::front(){
    // 경우1: arr에 수가 있는 경우
    if(a_cnt){
        return arr[a_front];
    }
    // 경우2: arr에는 없고, brr에 수가 있는 경우
    else if(b_cnt){
        return brr[b_front];
    }
    // 경우3: 덱에 정수가 없는 경우
    else{
        return -1;
    }
}

int deque::back(){
    // 경우1: brr배열에 수가 있는 경우
    if(b_cnt){
        return brr[b_back];
    }
    // 경우2: brr에는 없고, arr에 수가 있는 경우
    else if(a_cnt){
        return arr[a_back];
    }
    // 경우3: 덱에 정수가 없는 경우
    else{
        return -1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    deque d;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string a; int b;
        cin>>a;
        if(a=="push_front"){
            cin>>b;
            d.push_front(b);
        }
        else if(a=="push_back"){
            cin>>b;
            d.push_back(b);
        }
        else if(a=="pop_front"){
            cout<<d.pop_front()<<"\n";
        }
        else if(a=="pop_back"){
            cout<<d.pop_back()<<"\n";
        }
        else if(a=="size"){
            cout<<d.size()<<"\n";
        }
        else if(a=="empty"){
            cout<<d.empty()<<"\n";
        }
        else if(a=="front"){
            cout<<d.front()<<"\n";
        }
        else{ // a == "back"
            cout<<d.back()<<"\n";
        }
    } // for문 끝
    return 0;
}