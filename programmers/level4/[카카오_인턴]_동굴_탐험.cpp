#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
bool visit[200001];
set<int> adj[200001];
int par[200001],cnt,total;
bool sol(int prv, int n){
    if(par[n]!=-1 && !visit[par[n]]) return 0;
    if(!visit[n]) cnt++;
    visit[n]=1;
    bool ret=1;
    for(int nxt : adj[n]){
        if(nxt!=prv && !sol(n,nxt)) ret=0;
    }
    if(ret && n!=0) {
        adj[prv].erase(n);
        adj[n].erase(prv);
    }
    return ret;
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    memset(par,-1,sizeof(par));
    for(auto& p : path) adj[p[0]].insert(p[1]), adj[p[1]].insert(p[0]);
    for(auto& o : order) par[o[1]]=o[0];
    while(1){
        cnt=0;
        sol(-1,0);
        if(cnt==0) return 0;
        total+=cnt;
        if(total==n) return 1;
    }
}


// #include <vector>
// using namespace std;
// bool visit[200001],finished[200001];
// vector<int> tadj[200001],adj[200001];
// void dfs(int prv,int n){
//     for(auto nxt : tadj[n]){
//         if(prv!=nxt) {
//             adj[nxt].push_back(n);
//             dfs(n,nxt);
//         }
//     }
// }
// bool dfs2(int n){
//     visit[n]=1;
//     for(auto nxt : adj[n]){
//         if(!visit[nxt]){
//             if(!dfs2(nxt)) return 0;
//         }else if(!finished[nxt]) return 0;
//     }
//     finished[n]=1;
//     return 1;
// }
// bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
//     for(auto& p : path) tadj[p[0]].push_back(p[1]), tadj[p[1]].push_back(p[0]);
//     dfs(-1,0);
//     for(auto& o : order) adj[o[1]].push_back(o[0]);
//     for(int i=0;i<n;i++) if(!visit[i] && !dfs2(i)) return 0;
//     return 1;
// }