#include <cstdio>
#include <queue>
using namespace std;
struct P{int y,x,k;};
int map[1000][1000],N,M,hy,hx,ey,ex,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
int visit[1000][1000][2];
int main(){
    scanf("%d%d%d%d%d%d",&N,&M,&hy,&hx,&ey,&ex);
    hy--,hx--,ey--,ex--;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) scanf("%d",&map[i][j]);
    
    queue<P> q;
    visit[hy][hx][0]=1;
    q.push({hy,hx,0});
    int cnt = 0;
    while(!q.empty()){
        int qsz = q.size();
        while(qsz--){
            auto f = q.front(); q.pop();
            if(f.y==ey && f.x==ex){
                printf("%d",cnt);
                return 0;
            }
            for(int i=0;i<4;i++){
                int ny = f.y+dy[i];
                int nx = f.x+dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(map[ny][nx]){
                    if(!f.k && !visit[ny][nx][1]) {
                        visit[ny][nx][1]=1;
                        q.push({ny,nx,1});
                    }
                }else if(!visit[ny][nx][f.k]){
                    visit[ny][nx][f.k]=1;
                    q.push({ny,nx,f.k});
                }
            }
        }
        cnt++;
    }
    puts("");
}
