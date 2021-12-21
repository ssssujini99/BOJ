#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, first, x, i, k=0;
    int arr[100001];
    vector<char> v;
    stack<int> s;

    cin>>n;

    for(int j=0; j<n; j++){
        cin>>arr[j];
    }

    // 첫번째 경우 예외처리
    for(i=1; i<=arr[0]; i++){
        s.push(i);
        v.push_back('+');
    }
    s.pop();
    v.push_back('-');

    // 두번째 경우부터
    for(int j=1; j<n; j++){
        if(s.empty()){
            while(i<=arr[j]){
                s.push(i++);
                v.push_back('+');
            }
            s.pop();
            v.push_back('-');
        }
        else if(s.top()>arr[j]){
            cout<<"NO\n";
            exit(1);
        }
        else if(s.top()<arr[j]){
            while(i<=arr[j]){
                s.push(i++);
                v.push_back('+');
            }
            s.pop();
            v.push_back('-');
        }
        else{ // s.top() == arr[j]
            s.pop();
            v.push_back('-');
        }
    }

    // 수열을 만들 수 있는 경우
    for(int i=0; i<v.size(); i++) cout<<v[i]<<"\n";
    return 0;
}