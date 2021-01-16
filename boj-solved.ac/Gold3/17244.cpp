#include <cstdio>
#include <queue>
using namespace std;
int N,M,S,E,sy,sx,ey,ex,visit[50][50][1<<5];
char map[50][50];
int pos[50][50],dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
struct P{
    int y,x,bmsk;
};
int main(){
    scanf("%d%d",&N,&M);
    int p=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='S') sy=i,sx=j;
            else if(map[i][j]=='E') ey=i,ex=j;
            else if(map[i][j]=='X') pos[i][j]=p++;
        }
    }
    queue<P> q;
    visit[sy][sx][0]=1;
    q.push({sy,sx,0});
    int cnt = 0;
    while(!q.empty()){
        int qsz = q.size();
        while(qsz--){

            P f = q.front(); q.pop();
            if(f.y==ey&&f.x==ex&&f.bmsk==(1<<p)-1){
                printf("%d",cnt);
                return 0;
            }
            for(int i=0;i<4;i++){
                int ny=f.y+dy[i], nx=f.x+dx[i];
                if(ny<0||nx<0||ny>=M||nx>=N||map[ny][nx]=='#') continue;

                if(map[ny][nx]=='X'){
                    int b = f.bmsk|(1<<pos[ny][nx]);
                    if(!visit[ny][nx][b]){
                        visit[ny][nx][b]=1;
                        q.push({ny,nx,b});
                    }
                }else{
                    if(!visit[ny][nx][f.bmsk]){
                        visit[ny][nx][f.bmsk]=1;
                        q.push({ny,nx,f.bmsk});
                    }
                }
            }
        }
        cnt++;
    }
}
