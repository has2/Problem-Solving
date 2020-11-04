//gold2 17136
#include <cstdio>
#include <algorithm>
using namespace std;
int map[10][10],r[6],ans=100;
bool poss(int y,int x,int l){
    for(int i=y;i<y+l;i++) for(int j=x;j<x+l;j++) if(i>=10 || j>=10 || !map[i][j]) return 0;
    return 1;
}
void check(int y,int x,int l,int v){
    for(int i=y;i<y+l;i++) for(int j=x;j<x+l;j++) map[i][j] = v;
}
bool ok(){
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) if(map[i][j]) return 0;
    return 1;
}
void sol(int y,int x,int cnt){
    if(y==10&&x==0){
        if(ok()) ans = min(ans,cnt);
        return;
    }
    if(!map[y][x]) {
        if(x+1<10) sol(y,x+1,cnt);
        else sol(y+1,0,cnt);
    }else{
        for(int i=1;i<6;i++){
            if(r[i]){
                if(poss(y,x,i)){
                    r[i]--;
                    check(y,x,i,0);
                    if(x+1<10) sol(y,x+1,cnt+1);
                    else sol(y+1,0,cnt+1);
                    r[i]++;
                    check(y,x,i,1);
                }
            }
        }
    }
}
int main(){
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) scanf("%d",&map[i][j]);
    for(int i=1;i<6;i++) r[i] = 5;
    sol(0,0,0);
    printf("%d",ans==100 ? -1 : ans);
}