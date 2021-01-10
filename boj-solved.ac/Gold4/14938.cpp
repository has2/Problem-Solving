#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,R,item[101],dist[101][101],inf=9e8,ans;
int main(){
    scanf("%d%d%d",&N,&M,&R);
    for(int i=1;i<=N;i++) scanf("%d",&item[i]);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i!=j) dist[i][j] = inf;
        }
    }
    while(R--){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        dist[a][b] = min(dist[a][b],l);
        dist[b][a] = min(dist[b][a],l);
    }

    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    for(int i=1;i<=N;i++){
        int sum=0;
        for(int j=1;j<=N;j++){
            if(dist[i][j]<=M) sum+=item[j];
        }
        ans = max(ans,sum);
    }
    printf("%d",ans);
}
