#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N,point[51],visit[51];
vector<int> adj[51];

int sol(int k){
    memset(visit,0,sizeof(visit));
    queue<int> q;
    visit[k]=1;
    q.push(k);
    int ret=0;
    while(!q.empty()){
        int qf = q.front(); q.pop();
        ret=max(ret,visit[qf]);
        for(int nxt : adj[qf]){
            if(!visit[nxt]){
                visit[nxt]=visit[qf]+1;
                q.push(nxt);
            }
        }
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    while(1){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==-1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mv = 1e7;
    vector<int> ans;
    for(int i=1;i<=N;i++) {
        point[i]=sol(i);
        mv=min(mv,point[i]);
    }
    for(int i=1;i<=N;i++) 
        if(point[i]==mv) ans.push_back(i);

    printf("%d %d\n",mv-1,ans.size());
    for(auto a : ans) printf("%d ",a);
}