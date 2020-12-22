#include <cstdio>
int N,M,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
char map[50][50];
int visit[50][50];
bool dfs(int y,int x,int k){
    visit[y][x]=k;
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny < 0 || nx < 0|| ny >=N || nx >= M || map[ny][nx]!=map[y][x]) continue; 
        if(visit[ny][nx]){
            if(k-visit[ny][nx]>1) return 1;
        } else if(dfs(ny,nx,k+1)) return 1;
    }
    return 0;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) scanf(" %c",&map[i][j]);  
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visit[i][j]){
                if(dfs(i,j,0)){
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    puts("No");
}