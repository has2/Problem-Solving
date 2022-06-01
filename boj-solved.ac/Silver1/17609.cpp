#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
int tc;
int sol(int l,int r,bool use){
    while(l<=r){
        if(s[l]==s[r]) {
            l++,r--;
            continue;
        }
        if(!use) return 2;
        int ret=2;
        if(s[l+1]==s[r]) {
            ret=sol(l+1,r,0);
            if(ret!=2) return 1;
        }
        if(s[l]==s[r-1]) {
            ret=sol(l,r-1,0); 
            if(ret!=2) return 1;
        }
        return ret;
    }
    return 0;
}
int main(){
    cin >> tc;
    while(tc--){
        cin >> s;
        printf("%d\n",sol(0,s.size()-1,1));
    } 
}
