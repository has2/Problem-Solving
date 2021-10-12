#include <cstdio>
#include <algorithm>
using namespace std;
int N,map[100][100];
bool check(int h,int w,int y,int x){
    for(int i=y;i<y+h;i++)
        for(int j=x;j<x+w;j++)
            if(!map[i][j]) return false;
    return true;
}
bool check(int h,int w){
    for(int i=0;i<=100-h;i++)
        for(int j=0;j<=100-w;j++)
            if(check(h,w,i,j)) return true;
    return false;
}
int main(){
    scanf("%d",&N);
    while(N--){
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i=y;i<y+10;i++)
            for(int j=x;j<x+10;j++) map[i][j]=1;
    }
    int ans=0;
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            if(check(i,j)) ans=max(ans,i*j);

    printf("%d",ans);
}