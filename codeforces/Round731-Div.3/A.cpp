#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
 
int tc,sy,sx,ey,ex,fy,fx;
bool visit[1001][1001];
 
bool same(int a,int b,int c){
    return (a==b&&b==c);
}
bool between(int a,int b,int c){
    if(a>c) swap(a,c);
    return (a<b&&b<c);
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d%d%d%d",&sx,&sy,&ex,&ey,&fx,&fy);
        int ans = abs(sx-ex)+abs(sy-ey);
        if(same(sx,fx,ex)&&between(sy,fy,ey) || same(sy,fy,ey)&&between(sx,fx,ex)){
            ans+=2;
        }
        printf("%d\n",ans);
    }
}