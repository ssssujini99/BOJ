#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin>>s;
    vector<string> v;
    int size = s.size();

    for(int i=0; i<s.size(); i++){
        v.push_back(s.substr(i, size));
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) cout<<v[i]<<endl;
    return 0;
}