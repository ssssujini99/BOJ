#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long double tmp;
    int arr[26];
    string s;
    stack<long double> st;

    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++){
        cin>>tmp;
        arr[i]=tmp;
    }

    for(int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z'){ // 문자가 나왔을 경우 -> 스택에 넣기
            st.push(arr[s[i]-'A']);
        }
        else{ // 연산자가 나왔을 경우 -> 스택에 빼서 연산 후 다시 스택에 넣기
            long double t2 = st.top(); st.pop();
            long double t1 = st.top(); st.pop();

            if(s[i]=='+'){
                st.push(t1 + t2);
            }
            else if(s[i]=='-'){
                st.push(t1 - t2);
            }
            else if(s[i]=='*'){
                st.push(t1 * t2);
            }
            else if(s[i]=='/'){
                st.push(t1 / t2);
            }

        }
    } // for문 끝
    
    cout<<fixed;
    cout.precision(2); // 소수점 둘째자리까지 출력하기
    cout<<st.top()<<endl;
    return 0;
}