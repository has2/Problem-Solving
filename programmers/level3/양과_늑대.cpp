#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N,ans;
vector<int> adj[17],info;
void sol(int n,set<int> s,int a,int b){
    if(info[n]) b++;
    else a++;
    if(b>=a) return;
    s.erase(n);
    ans=max(a,ans);
    for(auto nxt : adj[n]) s.insert(nxt); 
    for(auto v : s) sol(v,s,a,b);
}
int solution(vector<int> _info, vector<vector<int>> edges) {
    N=info.size();
    info=_info;
    for(auto eg : edges) adj[eg[0]].push_back(eg[1]);
    sol(0,{0},0,0);
    return ans;
}