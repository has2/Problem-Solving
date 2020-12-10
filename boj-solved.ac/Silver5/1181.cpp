#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string& a,string& b){
    if(a.size() < b.size()) return 1;
    else if(a.size() == b.size()) return a < b;
    return 0;
}
int main(){
    int n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string s[20000];
    
    for(int i=0;i<n;i++) cin >> s[i];
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++) {
        if(i==0||s[i-1]!=s[i]) cout << s[i] << '\n';
    }
}