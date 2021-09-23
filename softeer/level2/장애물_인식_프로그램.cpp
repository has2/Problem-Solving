#include <cstdio>
#include <set>
using namespace std;
int N,map[25][25],dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
bool visit[25][25];
int dfs(int y,int x){
    visit[y][x]=1;
    int ret=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=N||nx>=N||!map[ny][nx]||visit[ny][nx]) continue;
        ret+=dfs(ny,nx);
    }
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) scanf("%1d",&map[i][j]);
    multiset<int> ans;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(map[i][j] && !visit[i][j]) ans.insert(dfs(i,j));
    printf("%d\n",ans.size());
    for(auto v : ans) printf("%d\n",v);
}