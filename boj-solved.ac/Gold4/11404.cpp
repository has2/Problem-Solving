#include <cstdio>
#include <algorithm>
int N,M,dist[101][101],INF=9e8;
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            dist[i][j] = INF;
            if(i==j) dist[i][j] = 0;
        }
    }
    
    for(int i=0;i<M;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c < dist[a][b]) dist[a][b] = c;
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j] = std::min(dist[i][j],dist[i][k]+dist[k][j]); 
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%d ",dist[i][j]==INF ? 0:dist[i][j]);
        }
        puts("");
    }
}