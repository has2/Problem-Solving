#include <cstdio>
#include <cstring>
int N,M,a[102][102],b[102][102],tmp[102][102];
int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
void dfs(int y,int x){
    b[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>N||nx>M||a[ny][nx]||b[ny][nx]) continue;
        dfs(ny,nx);
    }
}
int dfs2(int y,int x){
    b[y][x]=1;
    int ret=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(a[ny][nx] && !b[ny][nx]) ret+=dfs2(ny,nx);
    }
    return ret;
}
int cnt(){
    memset(b,0,sizeof(b));
    int ret=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(a[i][j] && !b[i][j]) ret+=dfs2(i,j);
    return ret;
}
void rmv(){
    memset(b,0,sizeof(b));
    memset(tmp,0,sizeof(tmp));
    dfs(0,0);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            bool ok=0;
            for(int k=0;k<4;k++){
                int ny=i+dy[k],nx=j+dx[k];
                if(b[ny][nx]){
                    ok=1;
                    break;
                }
            }
            tmp[i][j]=ok;
        }
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(tmp[i][j]) a[i][j]=0;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scanf("%d",&a[i][j]);
    int prev=cnt();
    for(int t=0;;t++){
        int cur=cnt();
        if(cur==0) {
            printf("%d\n%d",t,prev);
            return 0;
        }
        rmv();
        prev=cur;
    }
}