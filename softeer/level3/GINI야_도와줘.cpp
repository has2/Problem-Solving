#include <cstdio>
#include <queue>
using namespace std;
int R,C,dy[4]={-1,1,0,0},dx[4]={0,0,1,-1},ey,ex;
char map[50][50];
bool visit1[50][50],visit2[50][50];
int main(){
    scanf("%d%d",&R,&C);
    queue<pair<int,int>> q1,q2;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='W') {
                visit1[i][j]=1;
                q1.push({i,j});
            }
            else if(map[i][j]=='H') ey=i,ex=j;
            else if(map[i][j]=='*') {
                visit2[i][j]=1;
                q2.push({i,j});
            }
        }
    }
    int ans=0;
    while(!q1.empty()){
        int sz = q2.size();
        while(sz--){
            auto [cy,cx] = q2.front(); q2.pop();  
            for(int k=0;k<4;k++){
                int ny=cy+dy[k],nx=cx+dx[k];
                if(ny<0||nx<0||ny>=R||nx>=C||map[ny][nx]=='X'||map[ny][nx]=='H'||visit2[ny][nx]) continue;
                visit2[ny][nx]=1;
                q2.push({ny,nx});
            }
        }
        sz = q1.size();
        while(sz--){
            auto [cy,cx] = q1.front(); q1.pop();  
            if(cy==ey&&cx==ex){
                printf("%d",ans);
                return 0;
            }
            for(int k=0;k<4;k++){
                int ny=cy+dy[k],nx=cx+dx[k];
                if(ny<0||nx<0||ny>=R||nx>=C||map[ny][nx]=='X'||visit1[ny][nx]||visit2[ny][nx]) continue;
                visit1[ny][nx]=1;
                q1.push({ny,nx});
            }
        }
        ans++;
    }
    puts("FAIL");
}