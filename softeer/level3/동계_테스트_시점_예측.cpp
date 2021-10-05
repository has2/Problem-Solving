#include <cstdio>
#include <cstring>
int N,M,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
int map[100][100],cnt[100][100],visit[100][100],ans;
void dfs(int y,int x){
    visit[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<0||nx<0||ny>=N||nx>=M||visit[ny][nx]) continue;
        if(map[ny][nx]){
            cnt[ny][nx]++;
        }else{
            dfs(ny,nx);
        }
    }
}
bool exist(){
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) if(map[i][j]) return true;
    return false;
}
int main(){
    bool ok=0;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) {
            scanf("%d",&map[i][j]);
            if(map[i][j]) ok=1;
        }
    while(ok){
        ans++;
        dfs(0,0);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++) if(cnt[i][j]>=2) map[i][j]=0;
        ok=exist();
        memset(visit,0,sizeof(visit));
        memset(cnt,0,sizeof(cnt));
    }
    printf("%d",ans);
}