#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,T,board[101][101],visit[101][101][2];
int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
struct P{
    int y,x,k;
};
int main(){
    scanf("%d%d%d",&N,&M,&T);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) scanf("%d",&board[i][j]);
    queue<P> q;
    visit[0][0][0]=1;
    q.push({0,0,0});
    int cnt=0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [y,x,k] = q.front(); q.pop();
            if(y==N-1&&x==M-1){
                printf("%d",cnt);
                return 0;
            }
            for(int i=0;i<4;i++){
                int ny=y+dy[i], nx=x+dx[i],nk=k;
                if(board[ny][nx]==2) nk=1;
                if(ny<0||nx<0||ny>=N||nx>=M||visit[ny][nx][nk]) continue;
                if(board[ny][nx]==1&&nk==0) continue;
                visit[ny][nx][nk]=1;
                q.push({ny,nx,nk});
            }
        }
        cnt++;
        if(cnt>T) break;
    }
    puts("Fail");
}