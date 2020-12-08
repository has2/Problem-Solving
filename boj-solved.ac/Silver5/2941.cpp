#include <string>
#include <iostream>
using namespace std;
string s[8],in;
int n,ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> in;
    s[0]="dz=",s[1]="c-",s[2]="c=",s[3]="d-";
    s[4]="lj",s[5]="nj",s[6]="s=",s[7]="z="; 
    int len = in.size();
    for(int i=0;i<len;i++){
        ans++;
        int idx;
        for(auto st : s){
            if((idx=in.find(st))==0){
                int sz = st.size();
                in = in.substr(idx+sz);
                i+=sz-1;
                break;
            }
        }
        if(idx!=0) in=in.substr(1); 
    }
    cout << ans;
}