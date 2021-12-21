#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    stack<char> s;
    char arr[51];
    cin>>n;
    cin.ignore(); // 입력버퍼에 있는 엔터 지우기

    for(int i=0; i<n; i++){
        cin.getline(arr, 51, '\n');

        int j;
        for(j=0; j<51; j++){
            if(arr[j]=='(') s.push(arr[j]);
            else if(arr[j]==')'){
                if(s.empty()){
                    cout<<"NO\n"; // 안되는 경우1: ')'가 나왔을 때 지울 '('가 없을 경우
                    break;
                }
                else s.pop();
            }
            else{ // NULL인 경우
                break;
            }
        } // 내부 for문 끝
        if(arr[j]) continue; // 예외처리: 내부에서 NO로 끝난 경우

        if(s.empty()) cout<<"YES\n";
        else{
            cout<<"NO\n"; // 안되는 경우2: ')'는 끝났는데 '('가 남아있는 경우
            while(!s.empty()) s.pop();
        }
    }
    return 0;
}