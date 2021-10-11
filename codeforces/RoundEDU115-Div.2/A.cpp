#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
int t,n,mp[3][101];
bool visit[3][101];
int dy[4] = {1,0,1,-1};
int dx[4] = {1,1,0,1};
bool bfs(){
 
    queue<pair<int,int>> q;
    memset(visit,0,sizeof(visit));
 
    q.push({1,1});
    visit[1][1]=1;
 
    while(!q.empty()){
 
        auto [y,x] = q.front(); q.pop();
        if(y==2&&x==n) return true;
        for(int i=0;i<4;i++){
            int ny=y+dy[i], nx=x+dx[i];
            if(ny<1||nx<1||ny>2||nx>n||visit[ny][nx]||mp[ny][nx]) continue;
            visit[ny][nx]=1;
            q.push({ny,nx}); 
        }
    }
    return false;
}
 
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=2;i++)
            for(int j=1;j<=n;j++) scanf("%1d",&mp[i][j]);
        puts(bfs()?"YES":"NO");
 
    }
}