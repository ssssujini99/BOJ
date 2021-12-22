#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int cnt=1, sum=0;
    getline(cin, s);

    for(int i=1; i<s.size(); i++){
        // 레이저가 나온 경우
        if(s[i-1]=='(' && s[i]==')'){
            sum += (--cnt);
        }
        else if(s[i]=='('){
            cnt++; // 막대 개수 증가
        }
        // 그냥 ')'인 경우 -> 막대 한 개가 끝나는 경우
        else{
            sum ++; // 잘라진 개수 1객 증가
            cnt --; // 막대 하나 감소 -> 마무리 되니까
        }
    }

    cout<<sum<<endl;
}