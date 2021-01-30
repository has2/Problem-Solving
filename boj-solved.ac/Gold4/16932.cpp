#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int N,M,map[1000][1000],cnt[1000001];
int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
bool visit[1000][1000];
int dfs(int y,int x,int k){
    visit[y][x]=1;
    map[y][x]=k;
    int ret=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=N||nx>=M||!map[ny][nx]||visit[ny][nx]) continue;
        ret+=dfs(ny,nx,k);
    }
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) scanf("%d",&map[i][j]);

    int id=1;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(!visit[i][j] && map[i][j]) {
                cnt[id]=dfs(i,j,id);
                id++;
            }
    int ans=0;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            if(map[y][x]) continue;
            int c=0;
            set<int> s;
            for(int i=0;i<4;i++){
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=N||nx>=M||!map[ny][nx]) continue;
                s.insert(map[ny][nx]);
            }
            for(auto k : s) c+=cnt[k];
            ans=max(c,ans);
        }
    }
    printf("%d",ans+1);
}