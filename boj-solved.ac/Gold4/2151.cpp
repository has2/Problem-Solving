#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int N,visit[50][50][2],sy=-1,sx,ey,ex;
char map[50][50];
struct P{
    int y,x,d,k;
};
int main(){ 
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='#') {
                if(sy==-1)sy=i,sx=j;
                else ey=i,ex=j;
            }
        }
    }
    memset(visit,-1,sizeof(visit));
    queue<P> q;
    for(int i=0;i<4;i++) {
        q.push({sy,sx,i,0});
        visit[sy][sx][i%2]=0;
    }
    while(!q.empty()){

        P f = q.front(); q.pop();
        int ny = f.y+dy[f.d], nx = f.x+dx[f.d];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx]=='*') continue;
        
        if(visit[ny][nx][f.d%2]==-1 || visit[ny][nx][f.d%2] > f.k) {
            visit[ny][nx][f.d%2] = f.k;
            q.push({ny,nx,f.d,f.k});
        }        
        if(map[ny][nx]=='!'){
            if(visit[ny][nx][(f.d+1)%2]==-1 || visit[ny][nx][(f.d+1)%2] > f.k+1) {
                visit[ny][nx][(f.d+1)%2] = f.k+1;
                q.push({ny,nx,(f.d+1)%2,f.k+1});
                q.push({ny,nx,2+(f.d+1)%2,f.k+1});
            }            
        }
    }
    int ans = 9e8;
    if(visit[ey][ex][1]!=-1) ans = min(ans,visit[ey][ex][1]);
    if(visit[ey][ex][0]!=-1) ans = min(ans,visit[ey][ex][0]);
    printf("%d",ans);
}