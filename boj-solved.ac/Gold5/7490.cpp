#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int tc,N;
vector<string> ans;
void sol(int n,int v,string str){
    if(n==N+1) {
        if(v==0) ans.push_back(str.substr(1));
        return;
    }
    sol(n+1,v+n,str+"+"+to_string(n));
    if(n<=N-1) sol(n+2,v+10*n+n+1,str+"+"+to_string(n)+" "+to_string(n+1));
    
    if(n==1) return;

    sol(n+1,v-n,str+"-"+to_string(n));
    if(n<=N-1) sol(n+2,v-(10*n+n+1),str+"-"+to_string(n)+" "+to_string(n+1));
}
int main(){
    cin >> tc;
    while(tc--){
        cin >> N;
        sol(1,0,"");
        sort(ans.begin(),ans.end());
        for(auto a : ans) cout << a << '\n';
        cout << '\n';
        ans.clear();
    }
}