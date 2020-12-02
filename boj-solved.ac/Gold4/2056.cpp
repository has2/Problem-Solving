#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N,work[10001],total[10001],in[10001],ret;
vector<int> adj[10001];
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int ac,pre;
        scanf("%d%d",&work[i],&ac);
        in[i] = ac;
        for(int j=0;j<ac;j++){
            scanf("%d",&pre);
            adj[pre].push_back(i);
        }
    }
    queue<int> q;
    for(int i=1;i<=N;i++) if(!in[i]) q.push(i);
    while(!q.empty()){
        int qf = q.front(); q.pop();
        ret = max(ret,total[qf]+work[qf]);
        for(auto nxt : adj[qf]){
            total[nxt] = max(total[nxt],total[qf]+work[qf]);
            if(--in[nxt]==0) q.push(nxt);
        }

    }   
    printf("%d",ret);
}