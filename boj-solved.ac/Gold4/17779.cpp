#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N,map[21][21],A[21][21],total,ans=1e8;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
bool check(int d1,int d2,int x,int y){
    bool r = d1 >= 1 && d2 >= 1 && 1 <= x && x < x+d1+d2 && x+d1+d2 <= N;
    bool c = 1 <= y-d1 && y-d1 < y && y < y+d2 && y+d2 <=N;
    return r&&c;
}
void mask(int d1,int d2,int x,int y){
    int sx,sy,dx,dy;

    sx=x,sy=y,dx=1,dy=-1;
    for(int i=0;i<=d1;i++) {
        map[sx][sy] = 1;
        sx+=dx,sy+=dy;
    }
    sx=x,sy=y,dx=1,dy=1;
    for(int i=0;i<=d2;i++) {
        map[sx][sy] = 1;
        sx+=dx,sy+=dy;
    }
    sx=x+d1,sy=y-d1,dx=1,dy=1;
    for(int i=0;i<=d2;i++) {
        map[sx][sy] = 1;
        sx+=dx,sy+=dy;
    }  
    sx=x+d2,sy=y+d2,dx=1,dy=-1;
    for(int i=0;i<=d1;i++) {
        map[sx][sy] = 1;
        sx+=dx,sy+=dy;
    }     
}

int dfs(int d1,int d2,int x,int y,int r,int c,int k){
    if(k==1){
        if(!(1<=r&&r<x+d1&&1<=c&&c<=y)) return 0;
    }else if(k==2){
        if(!(1<=r&&r<=x+d2&&y<c&&c<=N)) return 0;
    }else if(k==3){
        if(!(x+d1<=r&&r<=N&&1<=c&&c<y-d1+d2)) return 0;
    }else if(k==4){
        if(!(x+d2<r&&r<=N&&y-d1+d2<=c&&c<=N)) return 0;
    }
    map[r][c] = k;
    int ret = A[r][c];
    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr < 1 || nc < 1 || nr > N || nc > N || map[nr][nc]) continue; 
        ret += dfs(d1,d2,x,y,nr,nc,k);
    }
    return ret;
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) {
            scanf("%d",&A[i][j]);
            total+=A[i][j];
        }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int d1=1;d1<=N;d1++){
                for(int d2=1;d2<=N;d2++){
                    if(!check(d1,d2,i,j)) continue;
                    memset(map,0,sizeof(map));
                    mask(d1,d2,i,j);
                    int sx = 1,sy=1;
                    vector<int> sum;
                    sum.push_back(dfs(d1,d2,i,j,1,1,1));
                    sum.push_back(dfs(d1,d2,i,j,1,N,2));
                    sum.push_back(dfs(d1,d2,i,j,N,1,3));
                    sum.push_back(dfs(d1,d2,i,j,N,N,4));
                    int rm = total;
                    for(int i=0;i<4;i++) rm -= sum[i];
                    sum.push_back(rm);
                    sort(sum.begin(),sum.end());
                    ans = min(ans,sum.back()-sum.front());
                }
            }
        }
    }    
    printf("%d",ans);
}