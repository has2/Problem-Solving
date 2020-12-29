#include <cstdio>
int N,M,dist[201][201],inf=9e8,path[201][201];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) {
            dist[i][j]=inf;
            if(i==j) dist[i][j]=0;
        }
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dist[a][b]=dist[b][a]=c;
        path[a][b]=b;
        path[b][a]=a;
    }
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++) {
                if(dist[i][j] > dist[i][k]+dist[k][j]){
                   dist[i][j] = dist[i][k]+dist[k][j];
                   if(i!=k) path[i][j] = path[i][k];
                }
            }    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) {
            if(path[i][j]) printf("%d ",path[i][j]);
            else printf("%c ",'-');
        }        
        puts("");
    }
}