#include <cstdio>
#include <algorithm>
using namespace std;
int T,N,M,K,dist[101][101],inf=9e8,frd[101];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                dist[i][j]=inf;
                if(i==j) dist[i][j]=0;
            }
        }
        while(M--){
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            dist[v][u]=dist[u][v]=d;
        }
        scanf("%d",&K);
        for(int i=0;i<K;i++) scanf("%d",&frd[i]);

        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
        int ans=inf,idx=-1;
        for(int i=1;i<=N;i++){
            int v=0;
            for(int j=0;j<K;j++) v+=dist[i][frd[j]];
            if(ans>v){
                idx=i;
                ans=v;
            }
        }
        printf("%d\n",idx);
    }
}