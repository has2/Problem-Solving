#include <cstdio>
int ans,K,a[6][6],dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
int sol2(int y,int x,int c,int t){
    if(y==5&&x==5) return c==t && c+t==24-K;
    int ret =0;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<1||nx<1||ny>5||nx>5||a[ny][nx]) continue;
        a[ny][nx]=1;
        ret+=sol2(ny,nx,c+1,t);
        a[ny][nx]=0;
    }
    return ret;
}
void sol(int y,int x,int c){
    int v = sol2(y,x,0,c);
    ans+=v;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<1||nx<1||ny>5||nx>5||a[ny][nx]) continue;
        a[ny][nx]=1;
        sol(ny,nx,c+1);
        a[ny][nx]=0;
    }
}
int main(){
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        int y,x;
        scanf("%d%d",&y,&x);
        a[y][x]=1;
    }
    a[1][1]=1;
    sol(1,1,0);
    printf("%d",ans);
}