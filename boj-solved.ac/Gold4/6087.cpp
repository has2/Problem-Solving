#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
char map[100][100];
int dy[4] = {-1,1,0,0},ans=1e9;
int dx[4] = {0,0,1,-1};
int H,W,sy=-1,sx,ey,ex,visit[100][100][4];
struct P{
    int y,x,k,d;
};
int main(){
    scanf("%d%d",&W,&H);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int d=0;d<4;d++) visit[i][j][d]=9e8;
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='C'){
                if(sy==-1) sy=i,sx=j;
                else ey=i,ex=j;
            }
        }
    }
    queue<P> q;
    for(int i=0;i<4;i++) q.push({sy,sx,0,i});
    
    while(!q.empty()){
        P qf = q.front(); q.pop();
        if(qf.y==ey&&qf.x==ex) ans = min(ans,visit[ey][ex][qf.d]);
        for(int i=0;i<4;i++){
            int ny = qf.y+dy[i];
            int nx = qf.x+dx[i];
            if(ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx]=='*') continue; 
            if(qf.d/2!=i/2){
                if(qf.k+1 < visit[ny][nx][i]) {
                    q.push({ny,nx,qf.k+1,i});
                    visit[ny][nx][i] = qf.k+1;
                }
            }else if(qf.d==i){
                if(qf.k < visit[ny][nx][i]) {
                    q.push({ny,nx,qf.k,i});
                    visit[ny][nx][i] = qf.k;
                }               
            }
        }
    }
    printf("%d",ans);
}