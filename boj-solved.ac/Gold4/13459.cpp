#include <cstdio>
#include <queue>
using namespace std;
struct P{
    int ry,rx,by,bx;
};
int N,M;
bool visit[11][11][11][11];
char map[11][11];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
int main(){
    scanf("%d%d",&N,&M);
    P p;
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) {
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='R') {
                p.ry=i,p.rx=j;
                map[i][j]='.';
            }
            else if(map[i][j]=='B') {
                p.by=i,p.bx=j;
                map[i][j]='.';
            }
        }
    queue<P> q;
    q.push(p);
    visit[p.ry][p.rx][p.by][p.bx] = 1;
    int k =0;
    while(!q.empty()){
        if(k==10) break;
        int sz = q.size();
        while(sz--){
            P p = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int nby,nbx,nry,nrx;
                int ty=p.by+dy[i],tx=p.bx+dx[i];
                int meet = 0;
                while(map[ty][tx] !='#' && map[ty][tx] != 'O') {
                    if(ty==p.ry&&tx==p.rx) meet = 1;
                    ty+=dy[i],tx+=dx[i];
                }
                if(map[ty][tx]=='O') continue;
                ty-=(1+meet)*dy[i],tx-=(1+meet)*dx[i];
                nby = ty, nbx = tx;
                
                ty=p.ry+dy[i],tx=p.rx+dx[i];
                meet = 0;
                while(map[ty][tx] !='#' && map[ty][tx] != 'O') {
                    if(ty==p.by&&tx==p.bx) meet = 1;
                    ty+=dy[i],tx+=dx[i];
                }          
                if(map[ty][tx]=='O') {
                    puts("1");
                    return 0;
                }
                ty-=(1+meet)*dy[i],tx-=(1+meet)*dx[i];
                nry = ty, nrx = tx;       

                if(!visit[nry][nrx][nby][nbx]){
                    visit[nry][nrx][nby][nbx]=1;
                    q.push({nry,nrx,nby,nbx});
                }
            }
        }
        k++;
    }
    puts("0");
}