#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dy[5]={-1,1,0,0,1000};
int dx[5]={0,0,1,-1,1000};
int N,M,total,ans,inf=987654321;
char map[31][31];
bool visit[31][31];
bool check(int y,int x,int d){
    int ny=y+dy[d];
    int nx=x+dx[d];
    return !(ny<0||nx<0||ny>=N||nx>=M||map[ny][nx]=='*'||visit[ny][nx]);
}
void sol(int y,int x,int d,int cnt,int t){
    visit[y][x]=1;
    if(t==total){
        ans=min(ans,cnt);
        visit[y][x]=0;
    }
    if(check(y,x,d)){
        sol(y+dy[d],x+dx[d],d,cnt,t+1);
    }else{
        for(int i=0;i<4;i++){
            if(check(y,x,i)){
                sol(y+dy[i],x+dx[i],i,cnt+1,t+1);
            }
        }
    }
    visit[y][x]=0;
}

int main(){
    int s=0;
    while(scanf("%d%d",&N,&M)!=-1){
        memset(map,0,sizeof(map));
        ans=inf;
        total=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++) {
                scanf(" %c",&map[i][j]);
                if(map[i][j]=='.') total++;      
            }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]=='.'){
                    memset(visit,0,sizeof(visit));
                    sol(i,j,4,0,1);
                }
            }
        }
        if(ans==inf) ans=-1;
        printf("Case %d: %d\n",++s,ans);
    }
}