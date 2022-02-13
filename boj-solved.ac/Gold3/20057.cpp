#include <map>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int N,board[501][501],ans;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
map<int,vector<pair<int,int>>> table = 
{
    {1,{{1,1},{-1,1}}},
    {2,{{2,0},{-2,0}}},
    {7,{{1,0},{-1,0}}},
    {10,{{1,-1},{-1,-1}}},
    {5,{{0,-2}}}
};
pair<int,int> cvt(int dir,int y,int x){
    for(int i=0;i<dir;i++) {
        int ny=-x,nx=y;
        y=ny,x=nx;
    }
    return {y,x};
}
void update(int dir,int fy,int fx){
    int total=board[fy][fx];
    int erased=0;
    for(auto [k,v] : table){
        for(auto p : v){
            auto c = cvt(dir,p.first,p.second);
            int ny=fy+c.first, nx=fx+c.second;
            int r = total*(k/100.0);
            erased+=r;
            if(ny>=1&&nx>=1&&ny<=N&&nx<=N) board[ny][nx]+=r;
            else ans+=r;
        }
    }
    board[fy][fx]=0;
    int ty=fy+dy[dir],tx=fx+dx[dir];
    if(ty>=1&&tx>=1&&ty<=N&&tx<=N) board[ty][tx]+=total-erased;
    else ans+=total-erased;
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) scanf("%d",&board[i][j]);
    int cy=N/2+1,cx=N/2+1,dir=0;
    for(int i=1;i<N;i++){
        int cnt=2;
        if(i==N-1) cnt=3;
        for(int j=0;j<cnt;j++){
            for(int k=0;k<i;k++){
                cy+=dy[dir];
                cx+=dx[dir];
                update(dir,cy,cx);
            }
            dir=(dir+1)%4;
        }
    }
    printf("%d",ans);
}