#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int H,W,ansd,ansy,ansx,sd,sy,sx;
char map[27][27];
bool visit[27][27];
vector<pair<int,int>> cand;
string ret="-1";

void sol(int y,int x,int d,int cnt,string cmd){

    if(cand.size()==cnt){
        if(ret=="-1" || cmd.size() < ret.size()){
            ret=cmd;
            ansy=sy,ansx=sx,ansd=sd;
            ansd=sd;
        }
        return;
    }

    for(int i=0;i<4;i++){
        int nd=(d+i)%4;
        string nxt="A";
        if(i==1) nxt="LA";
        else if(i==2) nxt="LLA";
        else if(i==3) nxt="RA";

        int ny1=y+dy[nd], nx1=x+dx[nd];
        int ny2=y+2*dy[nd], nx2=x+2*dx[nd];
        
        if(ny2<1||nx2<1||ny2>H||nx2>W) continue;
        if(map[ny1][nx1]!='#' || map[ny2][nx2]!='#' || visit[ny1][nx1] || visit[ny2][nx2]) continue;
       
        visit[ny1][nx1] = visit[ny2][nx2] = 1;
        sol(ny2,nx2,nd,cnt+2,cmd+nxt);
        visit[ny1][nx1] = visit[ny2][nx2] = 0;
    }
}
int main(){
    scanf("%d%d",&H,&W);
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='#') cand.push_back({i,j});
        }
    }
    for(auto [y,x] : cand){
        sy=y, sx=x;
        for(int k=0;k<4;k++){
            sd=k;
            memset(visit,0,sizeof(visit));
            visit[y][x]=1;
            sol(y,x,k,1,"");
        }
    }
    char cd = 'v';
    if(ansd==1) cd= '>';
    else if(ansd==2) cd='^';
    else if(ansd==3) cd='<';

    printf("%d %d\n",ansy,ansx);
    printf("%c\n",cd);
    printf("%s",ret.c_str());
}