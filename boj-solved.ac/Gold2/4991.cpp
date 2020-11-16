#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int w,h,sy,sx,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
char map[20][20];
bool visit[20][20][1<<10];
struct P{
    int y,x,b;
};
vector<P> info;

int getPos(int y,int x){
    for(int i=0;i<info.size();i++){
        if(info[i].y==y&&info[i].x==x) return i;
    }
    return 0;
}
int bfs(){
    memset(visit,0,sizeof(visit));
    queue<P> q;
    visit[sy][sx][0]=1;
    q.push({sy,sx,0});
    int ret = 0;
    while(!q.empty()){  
        int qsz = q.size();
        while(qsz--){
            P qf = q.front(); q.pop();
            if(qf.b==(1<<info.size())-1) return ret;
            for(int i=0;i<4;i++){
                int ny = qf.y+dy[i],nx = qf.x+dx[i],bm = qf.b;
                if(ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx] == 'x') continue;
                if(map[ny][nx]=='*') bm |= (1<<getPos(ny,nx));
                if(!visit[ny][nx][bm]){
                    visit[ny][nx][bm] = 1;
                    q.push({ny,nx,bm});
                }
            }
        }
        ret++;
    }
    return -1;    
}

int main(){
    while(1){
        scanf("%d%d",&w,&h);
        if(w==0) break;
        info.clear();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                scanf(" %c",&map[i][j]);
                if(map[i][j]=='o'){
                    sy=i,sx=j;  
                }else if(map[i][j]=='*'){
                    info.push_back({i,j,0});
                }
            }
        }
        printf("%d\n",bfs());
    }
}
