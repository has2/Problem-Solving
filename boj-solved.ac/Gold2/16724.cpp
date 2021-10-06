#include <cstdio>
int N,M,ans;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1},map[1000][1000];
int visit[1000][1000];
void dfs(int y,int x){
    visit[y][x]=1;
    int ny=y+dy[map[y][x]],nx=x+dx[map[y][x]];
    
    if(visit[ny][nx]==1) ans++;
    if(visit[ny][nx]==0) dfs(ny,nx);
    visit[y][x]=2;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c;
            scanf(" %c",&c);
            if(c=='U') map[i][j]=1;
            else if(c=='R') map[i][j]=2;
            else if(c=='L') map[i][j]=3;
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(visit[i][j]==0) dfs(i,j);
    printf("%d",ans);
}