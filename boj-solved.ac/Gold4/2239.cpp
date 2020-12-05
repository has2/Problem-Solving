#include <cstdio>
using namespace std;
int map[9][9],ok;
bool check(int y,int x,int k){
    for(int i=0;i<9;i++) {
        if(map[y][i]==k || map[i][x]==k) return 0;
    }
    int yy = (y/3)*3, xx=(x/3)*3;
    for(int i=yy;i<yy+3;i++)
        for(int j=xx;j<xx+3;j++) if(map[i][j]==k) return 0;
    
    return 1;
}
void sol(int y,int x){
    if(ok) return;
    if(y==9) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) printf("%d",map[i][j]);
            puts("");
        }
        ok = 1;
        return;
    }
    if(map[y][x]){
        if(x==8) sol(y+1,0);
        else sol(y,x+1);
    }else{
        for(int i=1;i<10;i++){
            if(check(y,x,i)){
                map[y][x] = i;
                if(x==8) sol(y+1,0);
                else sol(y,x+1);
                map[y][x] = 0;
            }
        }
    }
}
int main(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++) scanf("%1d",&map[i][j]);
    sol(0,0);
}
    
