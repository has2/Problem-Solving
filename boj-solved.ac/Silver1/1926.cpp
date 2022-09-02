#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[501][501],dy[4]={-1,1,0,0},dx[4]={0,0,1,-1},cnt,ans;
int dfs(int y,int x){
    a[y][x]=2;
    int ret=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]!=1) continue;
        ret+=dfs(ny,nx);
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                cnt++;
                ans = max(ans,dfs(i,j));
            }
        }
    }
    printf("%d\n%d",cnt,ans);
}