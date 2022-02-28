#include <cstdio>
#include <algorithm>
using namespace std;
int N,K,dist[11][11],seq[11],ans=9e8;
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) scanf("%d",&dist[i][j]);
        
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    int j=0;
    for(int i=0;i<N;i++) if(i!=K) seq[j++]=i;
    do{ 
        int t=dist[K][seq[0]];
        for(int i=1;i<N-1;i++) t+=dist[seq[i-1]][seq[i]];
        ans=min(t,ans);
    }while(next_permutation(seq,seq+N-1));
    printf("%d",ans); 
}