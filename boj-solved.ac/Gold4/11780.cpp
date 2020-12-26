#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int N,M,dist[101][101],path[101][101],INF=9e8;
void prt(int i,int j,vector<int>& tmp){
    if(i==j) {
        tmp.push_back(i);
        return;
    }
    int p = path[i][j];
    prt(i,p,tmp);
    if(i!=p) prt(p,j,tmp);
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) if(i!=j) dist[i][j]=INF;  
             
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(dist[a][b] > c){
           dist[a][b] = c;
           path[a][b] = a;
        }
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                   dist[i][j]=dist[i][k]+dist[k][j];
                   path[i][j]=k;
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            printf("%d ",dist[i][j]==INF ? 0 : dist[i][j]);
        puts("");
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!dist[i][j]) printf("0");
            else {
                vector<int> tmp;
                prt(i,j,tmp);
                tmp.push_back(j);
                printf("%d ",tmp.size());
                for(auto k : tmp) printf("%d ",k);
            }
            puts("");
        }
    }
}