#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
int ans=9e8;
bool check[10][10][10][10];
char map[10][10];
struct P{
    int y,x,rd;
};
struct RB{
    P r,b;
    int k;
};

int main(){

    scanf("%d%d",&N,&M);
    RB p;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='R') {
                p.r.y=i,p.r.x=j,p.r.rd=1;
                map[i][j]='.';
            }
            if(map[i][j]=='B') {
                p.b.y=i,p.b.x=j,p.b.rd=0;
                map[i][j]='.';
            }
        }
    }

    queue<RB> q;
    q.push(p);
    check[p.r.y][p.r.x][p.b.y][p.b.x]=1;

    int cnt=1;
    while(!q.empty()){

        int sz=q.size();
        while(sz--){

            auto qf = q.front(); q.pop();
            P r=qf.r, b=qf.b;
            for(int k=0;k<4;k++){
                P u=r,v=b;
                if(k==0) {
                    if(u.y>v.y) swap(u,v);
                }else if(k==1){
                    if(u.y<v.y) swap(u,v);
                }else if(k==2){
                    if(u.x<v.x) swap(u,v);
                }else {
                    if(u.x>v.x) swap(u,v);
                }

                int ny=u.y,nx=u.x;
                int fy,fx,fr,sy,sx,sr;
                bool ctn=0,t=0;
                while(1){
                    ny+=dy[k],nx+=dx[k];

                    if(map[ny][nx]=='#'){
                        ny-=dy[k],nx-=dx[k];
                        fy=ny,fx=nx,fr=u.rd;
                        break;
                    }
                    if(map[ny][nx]=='O'){
                        if(!u.rd) {
                            ctn=1;
                            break;
                        }
                        t=1;
                        break;
                    }
                }
                if(ctn) continue;

                ny=v.y,nx=v.x;
                while(1){
                    ny+=dy[k],nx+=dx[k];
                    if(map[ny][nx]=='#' || (ny==fy && nx==fx)){
                        ny-=dy[k],nx-=dx[k];
                        sy=ny,sx=nx,sr=v.rd;
                        break;
                    }

                    if(map[ny][nx]=='O'){
                        if(!v.rd){
                            ctn=1;
                            break;
                        }
                        t=1;
                        break;
                    }
                }
                if(ctn) continue;

                if(t) {
                    printf("%d",cnt);
                    return 0;
                }
                u={fy,fx,fr};
                v={sy,sx,sr};
                if(!u.rd) swap(u,v); 

                if(!check[u.y][u.x][v.y][v.x]){
                    check[u.y][u.x][v.y][v.x]=1;
                    RB nxt;
                    nxt.r=u;
                    nxt.b=v;
                    nxt.k=k;
                    q.push(nxt);
                }
            }
        }
        cnt++;
    }
    puts("-1");
}