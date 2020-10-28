#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int T,K,M,P,indegree[1001];
vector<int> adj[1001];
pair<int,int> stra[1001];

int solve(){

    memset(indegree,0,sizeof(indegree));
    memset(stra,0,sizeof(stra));
    for(int i=1;i<=M;i++) adj[i].clear();
    for(int i=0;i<P;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for(int i=1;i<=M;i++){
        if(!indegree[i]) {
            q.push(i);
            stra[i].first = 1;
        }
    }

    while(!q.empty()){
        int qf = q.front(); q.pop();
        if(stra[qf].second > 1) stra[qf].first++;
        if(qf==M) return stra[qf].first;
        for(int next : adj[qf]){
            if(stra[next].first < stra[qf].first){
                stra[next].first = stra[qf].first;
                stra[next].second = 1; 
            }else if(stra[next].first == stra[qf].first){
                stra[next].second++;
            }
            if(--indegree[next] == 0){
                q.push(next);
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++){
        scanf("%d%d%d",&K,&M,&P);
        printf("%d %d\n",tc,solve());
    }
}