#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,map[50][50],g,grp[2501],mxR,mxS;
int visit[50][50];
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
int dfs(int y,int x){
    visit[y][x] = g;
    int ret = 1;
    for(int i=0;i<4;i++){
        if((map[y][x] & (1<<i))==0){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visit[ny][nx]) continue;
            ret+=dfs(ny,nx);
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&map[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j]){
                g++;
                grp[g] = dfs(i,j);
                mxR = max(mxR,grp[g]);
            }
        }
    }
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            for(int i=0;i<4;i++){
                if((map[y][x] & (1<<i))>0){
                    int ny = y+dy[i], nx = x+dx[i];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if(visit[ny][nx] != visit[y][x]) mxS = max(mxS,grp[visit[ny][nx]]+grp[visit[y][x]]);
                }
            }
        }
    }
    printf("%d\n%d\n%d",g,mxR,mxS);
}