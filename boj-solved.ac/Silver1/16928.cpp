#include <cstdio>
#include <queue>
using namespace std;
int N,M,u,v,up[101],down[101];
bool visit[101];
int main(){
    scanf("%d%d",&N,&M);
    while(N--) scanf("%d%d",&u,&v), up[u]=v;
    while(M--) scanf("%d%d",&u,&v), down[u]=v;
    
    queue<int> q;
    q.push(1);
    visit[1]=1;
    int ret=0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int qf = q.front(); q.pop();
            if(qf==100){
                printf("%d",ret);
                return 0;
            }
            for(int k=1;k<7;k++){
                int nxt = qf+k;
                if(nxt>100) continue;
                int mv=0;
                if(up[nxt]) mv=up[nxt];
                if(down[nxt]) mv=down[nxt];
                if(mv!=0) nxt=mv;
                if(!visit[nxt]){
                    visit[nxt]=1;
                    q.push(nxt);
                }
            }
        }
        ret++;
    }
}