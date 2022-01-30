#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N,M,board[1001][1001],sy,sx;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
int visit[1001][1001];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) {
            scanf("%d",&board[i][j]);
            if(board[i][j]==2) sy=i,sx=j;
        }
    queue<pair<int,int>> q;
    q.push({sy,sx});
    
    int dist=1;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto [y,x] = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(ny<0||nx<0||ny>=N||nx>=M||board[ny][nx]!=1||visit[ny][nx]) continue;
                q.push({ny,nx});
                visit[ny][nx]=dist;
            }
        }
        dist++;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visit[i][j]==0 && board[i][j]==1) printf("-1 ");
            else printf("%d ",visit[i][j]);
        }
        puts("");
    }
}