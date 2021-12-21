#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> s1; // 커서의 왼쪽을 나타냄
    stack<char> s2; // 커서의 오른쪽을 나타냄
    string s; int n; char c1, c2;

    cin>>s;
    for(int i=0; i<s.size(); i++) s1.push_back(s[i]);
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>c1;

        if(c1=='L'){
            if(s1.size()==0) continue;

            s2.push(s1.back());
            s1.pop_back();
        }
        else if(c1=='D'){
            if(s2.empty()) continue;

            s1.push_back(s2.top());
            s2.pop();
        }
        else if(c1=='B'){
            if(s1.size()==0) continue;

            s1.pop_back();
        }
        else{ // c1=='P'
            cin>>c2;
            s1.push_back(c2);
        }
    }

    for(int i=0; i<s1.size(); i++) cout<<s1[i];
    while(!s2.empty()){
        cout<<s2.top();
        s2.pop();
    }
    cout<<endl;
    return 0;
}