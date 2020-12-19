#include <cstdio>
#include <queue>
using namespace std;
int N,M,cy[2],cx[2],dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
int visit[20][20][20][20];
char map[20][20];
struct P{
    int ay,ax,by,bx;
};
int move(int y,int x){
    if(y<0||x<0||y>=N||x>=M) return -1; 
    if(map[y][x]=='#') return 0;
    return 1;
}
int main(){
    scanf("%d%d",&N,&M);
    cy[0]=-1;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) {
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='o') {
                if(cy[0]==-1) cy[0]=i,cx[0]=j;
                else cy[1]=i,cx[1]=j;
                map[i][j]='.';
            }
        }
    visit[cy[1]][cx[1]][cy[0]][cx[0]]=visit[cy[0]][cx[0]][cy[1]][cx[1]]=1;
    queue<P> q;
    q.push({cy[0],cx[0],cy[1],cx[1]});
    int cnt=0;
    while(1){
        int sz = q.size();
        if(cnt++==10) break;
        while(sz--){
            P qf = q.front(); q.pop();
            for(int i=0;i<4;i++){   
                P n = qf;
                int ty = qf.ay+dy[i], tx=qf.ax+dx[i];
                int r1 = move(ty,tx);
                if(r1==1) n.ay=ty, n.ax=tx;
                
                ty = qf.by+dy[i], tx=qf.bx+dx[i];
                int r2 = move(ty,tx);
                if(r2==1) n.by=ty, n.bx=tx;
                if(r1==-1 && r2>=0 || r2==-1&&r1>=0) {
                    printf("%d",cnt);
                    return 0;
                }else if(r1+r2==-2 
                || visit[n.ay][n.ax][n.by][n.bx] || visit[n.by][n.bx][n.ay][n.ax]) continue; 

                q.push({n.ay,n.ax,n.by,n.bx});
                visit[n.by][n.bx][n.ay][n.ax] = visit[n.ay][n.ax][n.by][n.bx] = 1;
            }
        }
    }
    puts("-1");
}