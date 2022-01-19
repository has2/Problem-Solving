#include <cstdio>
#include <string>
#include <set>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
ll s,t;
string sol(ll sv,string sstr){
    queue<pair<ll,string>> q;
    q.push({sv,sstr});   
    set<ll> visit;
    visit.insert(sv);
    while(!q.empty()){
        auto [v,str] = q.front();
        q.pop();
        if(v==t) return str;
        
        if(v*v<=t && visit.find(v*v)==visit.end()) {
            visit.insert(v*v);
            q.push({v*v,str+"*"});
        }
        if(v+v<=t && visit.find(v+v)==visit.end()) {
            visit.insert(v+v);
            q.push({v+v,str+"+"});
        }

    }     
    return "0";
}
int main(){
    cin >> s >> t;
    if(s==t) {
        cout << 0;
        return 0;
    }
    string ans1 = sol(s,"");
    string ans2 = sol(1,"/");
    if(ans1=="0" && ans2=="0") cout << -1;
    else if(ans1=="0") cout << ans2;
    else if(ans2=="0") cout << ans1;
    else {
        if(ans1.size()<ans2.size()) cout << ans1;
        else if(ans1.size()>ans2.size()) cout << ans2;
        else{
            if(ans1<ans2) cout << ans1;
            else cout << ans2;    
        }   
    }
}