#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[26];
    fill_n(a, 26, -1); // c++ 배열 초기화하기
    string s;
    cin>>s;


    for(int i=0; i<s.size(); i++){
        if(a[s[i]-'a']==-1) a[s[i]-'a']=i;
    }

    for(int i=0; i<26; i++) cout<<a[i]<<" ";
    return 0;
}