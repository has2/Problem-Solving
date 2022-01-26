#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int N,M,ans[1001],inDegree[1001];
vector<int> adj[1001];
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        inDegree[v]++;
    }
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(!inDegree[i]) {
            q.push(i);
            ans[i]=1;
        }
    }
    int cur=2;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int qf = q.front();
            q.pop();
            for(auto nxt : adj[qf]){
                if(--inDegree[nxt]==0){
                    q.push(nxt);
                    ans[nxt]=cur;
                }
            }
        }
        cur++;
    }
    for(int i=1;i<=N;i++) printf("%d ",ans[i]);
}