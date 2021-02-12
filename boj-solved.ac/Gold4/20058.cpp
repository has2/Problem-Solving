#include <cstdio>
#include <algorithm>
using namespace std;
int N,Q,map[70][70],tmp[70][70],dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
bool visit[70][70];
int dfs(int y,int x){
    visit[y][x]=1;
    int ret=1;
    for(int i=0;i<4;i++){
        int ty=y+dy[i],tx=x+dx[i];
        if(map[ty][tx] && !visit[ty][tx]) ret += dfs(ty,tx);
    }
    return ret;
}
void move(int y,int x,int k){
    for(int l=k;l>=2;l-=2){    
        for(int i=0;i<l;i++) {
            tmp[y+i][x+l-1] = map[y][x+i];
            tmp[y+l-1][x+l-1-i] = map[y+i][x+l-1];
            tmp[y+l-1-i][x] = map[y+l-1][x+l-1-i];
            tmp[y][x+i] = map[y+l-1-i][x];
        }
        y++,x++;
    }
}
void query(int n){
    int k = 1<<n;
    for(int i=1;i<=(1<<N);i+=k)
        for(int j=1;j<=(1<<N);j+=k) move(i,j,k);
}
int main(){
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=(1<<N);i++){
        for(int j=1;j<=(1<<N);j++){
            scanf("%d",&map[i][j]);
            tmp[i][j]=map[i][j];
        }
    }
    int sum=0,sum2=0;
    while(Q--){
        int q;
        scanf("%d",&q);
        if(q!=0){
            query(q);
            for(int i=1;i<=(1<<N);i++){
                for(int j=1;j<=(1<<N);j++){
                    map[i][j]=tmp[i][j];
                }
            }
        }
        sum=0;
        for(int i=1;i<=(1<<N);i++){
            for(int j=1;j<=(1<<N);j++){
                int cnt=0;
                if(map[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    if(tmp[i+dy[k]][j+dx[k]]>0) cnt++;
                }
                if(cnt<3) map[i][j]--;
                sum+=map[i][j];
            }
        }
        for(int i=1;i<=(1<<N);i++)
            for(int j=1;j<=(1<<N);j++)
                tmp[i][j]=map[i][j];
    }
    for(int i=1;i<=(1<<N);i++)
        for(int j=1;j<=(1<<N);j++)
            if(map[i][j] && !visit[i][j]) sum2=max(sum2,dfs(i,j));
    printf("%d\n%d",sum,sum2);
}