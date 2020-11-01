#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
int N,M,in[32001];
vector<int> adj[32001];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        in[b]++;
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=N;i++){
        if(in[i]==0) pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top(); pq.pop();
        printf("%d ",cur);
        for(int next : adj[cur]){
            if(--in[next]==0){
                pq.push(next);
            }
        }
    }
}