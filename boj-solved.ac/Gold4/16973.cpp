#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,board[1001][1001],H,W,sy,sx,ey,ex,sum[1001][1001];
bool visit[1001][1001];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
bool check(int y,int x){
    if(y<1||x<1||y>N||x>M||y+H-1<1||x+W-1<1||y+H-1>N||x+W-1>M) return 0;
    if(sum[y+H-1][x+W-1]-sum[y-1][x+W-1]-sum[y+H-1][x-1]+sum[y-1][x-1]>0) return 0;
    return 1;
}
int bfs(){
    queue<pair<int,int>> q;
    q.push({sy,sx});
    visit[sy][sx]=1;
    int ret=0;
    while(!q.empty()){
        int sz= q.size();
        while(sz--){
            auto [y,x] =q.front(); q.pop();
            if(y==ey&&x==ex) return ret;
            for(int i=0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(!check(ny,nx) || visit[ny][nx]) continue;
                q.push({ny,nx});
                visit[ny][nx]=1;
            }
        }
        ret++;
    }
    return -1;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++) {
            scanf("%d",&board[i][j]);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+board[i][j];
        }

    scanf("%d%d%d%d%d%d",&H,&W,&sy,&sx,&ey,&ex);
    printf("%d",bfs());
}