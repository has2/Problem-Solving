    #include <cstdio>

    int N,dy[4]={0,0,1,-1};
    int dx[4]={1,-1,0,0},visit[40][40];
    int p[4],cnt;
    double ans;
    void sol(int y,int x,int k,double pr){
        visit[y][x]=1;
        if(k==N){
            visit[y][x]=0;
            cnt++;
            ans+=pr;
            return;
        }
        
        for(int i=0;i<4;i++){
            int ny=y+dy[i], nx=x+dx[i];
            if(!visit[ny][nx]){
                sol(ny,nx,k+1,pr*(p[i]/(double)100));
            }
        }
        visit[y][x]=0;
    }
    int main(){
        scanf("%d",&N);
        for(int i=0;i<4;i++) scanf("%d",&p[i]);
        sol(17,17,0,1);
        printf("%.11f",ans);
    }