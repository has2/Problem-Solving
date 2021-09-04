#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[250001];
priority_queue<int> pq;
int mxD,from;
void dfs(int p,int m,int cnt,bool f){
    if(mxD < cnt){
        mxD=cnt;
        from=m;
    }
    if(f && adj[m].size()==1) pq.push(cnt);
    for(auto nxt : adj[m])
        if(nxt!=p) dfs(m,nxt,cnt+1,f);
}
int solution(int n, vector<vector<int>> edges) {
    for(auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    dfs(0,1,0,0);
    
    int a = from; mxD=0;
    dfs(0,a,0,1);
    int t=pq.top(); pq.pop();
    if(t==pq.top()) return t;
    while(!pq.empty()) pq.pop();

    a=from; mxD=0;
    dfs(0,a,0,1);
    t=pq.top(); pq.pop();
    return t==pq.top() ? t : t-1;
}