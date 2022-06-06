#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dy[4]={-1,0,1,0},dx[4]={0,-1,0,1};
int line[6][4]={{0,0,1,1},{0,1,1,0},{1,0,0,1},{1,1,0,0},{1,0,1,0},{0,1,0,1}};
int N,k,board[52][52],visit[52][52];
int match(int i){
    if(i<2) return i+2;
    return i-2;
}
int dfs(int y,int x){
    if(y==N-1&&x==N-1){
        if(board[y][x]==2||board[y][x]==5) return 1;
        return -1;
    }
    if(y==0&&x==0){
        if(board[y][x]%2==0) return -1;
    }
    visit[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        int m = match(i);
        if(ny<0||nx<0||ny>=N||nx>=N||!line[board[y][x]][i]||!line[board[ny][nx]][m]||visit[ny][nx]) continue;
        int ret = dfs(ny,nx);
        if(ret==-1) return -1;
        return ret+1;
    }
    return -1;
}
int main(){
    scanf("%d%d",&N,&k);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&board[i][j]);
        }
    }
    int ans=9e8;
    if(k){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int t = board[i][j];
                for(int k=0;k<6;k++){
                    if(t!=k) {
                        board[i][j]=k;
                        memset(visit,0,sizeof(visit));
                        int ret = dfs(0,0);
                        if(ret!=-1) ans=min(ans,ret);
                    }
                }
                board[i][j]=t;
            }
        }       
    }else ans=dfs(0,0);
    printf("%d",ans == 9e8 ? -1 : ans);
}