#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> adj[200001];
int N,M,visit[200001],ip,ans[200001];
queue<int> q;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        while(1){
            scanf("%d",&ip);
            if(ip==0) break;
            adj[i].push_back(ip);
        }
    }
    memset(ans,-1,sizeof(ans));
    scanf("%d",&M);
    for(int i=0;i<M;i++) {
        scanf("%d",&ip);
        q.push(ip);
        visit[ip]=1;
        ans[ip]=0;
    }
    int time=1;
    while(!q.empty()){
        int sz = q.size();
        vector<int> tmp;
        while(sz--){
            auto qf = q.front(); q.pop();

            for(auto nxt : adj[qf]){
                if(!visit[nxt]){
                    int cnt=0;
                    for(auto nadj : adj[nxt]){
                        cnt+=visit[nadj];
                    }
                    if(adj[nxt].size() <= 2*cnt){
                        tmp.push_back(nxt);
                        ans[nxt]=time;
                    }
                }
            }
        }
        for(auto t : tmp){
            q.push(t);
            visit[t]=1;
        }
        time++;
    }
    for(int i=1;i<=N;i++) printf("%d ",ans[i]);
}