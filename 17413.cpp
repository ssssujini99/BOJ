#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    stack<char> st;
    getline(cin, s);

    for(int i=0; i<s.size(); i++){
        // 경우1: < > 사이는 그대로 출력
        if(s[i]=='<'){
            while(!(s[i]=='>')) cout<<s[i++];
            cout<<s[i]; // '>' 출력
        }
        // 경우2: 공백은 그대로 출력
        else if(s[i]==' '){
            cout<<s[i];
        }
        // 경우3: 단어인 경우 -> 거꾸로 출력하기
        else{
            while(s[i]!=' ' && s[i]!='<' && s[i]!='\0'){
                st.push(s[i++]);
            }
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            i--;
        }
    }
    cout<<endl;
    return 0;
}