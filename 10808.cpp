#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[26]={0, };
    string s;
    cin>>s;

    for(int i=0; i<s.size(); i++){
        a[s[i]-'a']++;
    }

    for(int i=0; i<26; i++) cout<<a[i]<<" ";
    return 0;
}