#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
 
int tc;
string s;
 
bool solve(){
    int cur=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a') {
            cur=i;
            break;
        }
    }
    if(cur==-1) return false;
    int l=cur,r=cur;
 
    int sz = s.size()-1;
    char target='b';
    while(sz--){
 
        if(l-1>=0){
            if(s[l-1]==target){
                l--;
                target++;
                continue;
            }
        }
        if(r+1<s.size()){
            if(s[r+1]==target){
                r++;
                target++;
                continue;
            }
        }
        return false;
    }
    return true;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        cin >> s;
        string ret = solve()?"YES":"NO";
        cout << ret << '\n';
    }
    
}