#include <cstdio>
#include <set>
using namespace std;
int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
int N,M,a[1000][1000],grp[1000][1000],cnt[1000001];
bool visit[1000][1000];
int dfs(int y,int x,int k){
    visit[y][x]=1;
    grp[y][x]=k;

    int ret=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<0||nx<0||ny>=N||nx>=M||a[ny][nx]||visit[ny][nx]) continue;
        ret+=dfs(ny,nx,k);
    }
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) scanf("%1d",&a[i][j]);
        
    int g=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!a[i][j] && !visit[i][j]){
                cnt[g]=dfs(i,j,g);
                g++;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!a[i][j]) continue;
            int v=0;
            set<int> p;
            for(int k=0;k<4;k++){
                int ny=i+dy[k],nx=j+dx[k];
                if(ny<0||nx<0||ny>=N||nx>=M||a[ny][nx]) continue;  
                p.insert(grp[ny][nx]);
            }
            for(auto q : p) v+=cnt[q];
            a[i][j]=v+1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d",a[i][j]%10);
        }
        puts("");
    }
}