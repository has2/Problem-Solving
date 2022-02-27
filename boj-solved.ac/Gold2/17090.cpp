#include <cstdio>
#include <cstring>
using namespace std;
int N,M,ans,visit[501][501],dp[501][501],board[501][501],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
int sol(int y,int x){
    visit[y][x]=1;
    int& ret =dp[y][x];
    if(ret!=-1) {
        visit[y][x]=0;
        return ret;
    }
    int d = board[y][x];
    int ny=y+dy[d],nx=x+dx[d];
    if(ny<0||nx<0||ny>=N||nx>=M) ret=1;
    else {
        if(visit[ny][nx]) ret=0;
        else ret = sol(ny,nx);
    }
    visit[y][x]=0;
    return ret; 
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            char d;
            scanf(" %c",&d);
            if(d=='R') board[i][j]=1;
            else if(d=='D') board[i][j]=2;
            else if(d=='L') board[i][j]=3;
        }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) {
            ans+=sol(i,j);
        }
    printf("%d",ans);
}