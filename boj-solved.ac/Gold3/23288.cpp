#include <cstdio>
#include <cstring>
using namespace std;
int N,M,K,board[22][22],dice[7]={0,1,2,3,4,5,6},visit[22][22];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
void move(int d){
    int tmp[7];
    for(int i=1;i<=6;i++) tmp[i]=dice[i];
    if(d==0){
        dice[1]=tmp[4];
        dice[3]=tmp[1];
        dice[4]=tmp[6];
        dice[6]=tmp[3];
    }else if(d==1){
        dice[1]=tmp[2];
        dice[2]=tmp[6];
        dice[5]=tmp[1];
        dice[6]=tmp[5];
    }else if(d==2){ 
        dice[1]=tmp[3];
        dice[4]=tmp[1];
        dice[3]=tmp[6];
        dice[6]=tmp[4];
    }else{
        dice[1]=tmp[5];
        dice[2]=tmp[1];
        dice[5]=tmp[6];
        dice[6]=tmp[2];
    }
}
int dfs(int y,int x){
    visit[y][x]=1;
    int ret=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(board[ny][nx] && board[ny][nx]==board[y][x] && !visit[ny][nx]){
            ret+=dfs(ny,nx);
        }
    }
    return ret;
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++) scanf("%d",&board[i][j]);
    int d=0,cy=1,cx=1,ans=0,cnt=0;;
    while(K--){
        int ny=cy+dy[d],nx=cx+dx[d];
        if(!board[ny][nx]){
            d=(d+2)%4;
            K++;
            continue;
        }
        move(d);
        if(dice[6]>board[ny][nx]) d=(d+1)%4;
        else if(dice[6]<board[ny][nx]) d=(d+3)%4;
        ans+=dfs(ny,nx)*board[ny][nx];
        memset(visit,0,sizeof(visit));
        cy=ny,cx=nx;
    }
    printf("%d",ans);
}   