//gold4 3584 가장 가까운 공통 조상 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tc,N,par[10001],rt,p1,p2;
int getH(int n){
    int ret=0,cur=n;
    while(cur!=rt){
        cur=par[cur];
        ret++;
    }
    return ret;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        memset(par,0,sizeof(par));
        for(int i=1;i<N;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            par[b]=a;
        }
        scanf("%d%d",&p1,&p2);
        for(int i=1;i<=N;i++){
            if(par[i]==0) {
                rt=i;
                break;
            }
        }
        int p1h=getH(p1),p2h=getH(p2);
        if(p1h<p2h) {
            swap(p1,p2);
            swap(p1h,p2h);
        }
        for(int i=0;i<p1h-p2h;i++) p1=par[p1];
        while(p1!=p2){
            p1=par[p1];
            p2=par[p2];
        }
        printf("%d\n",p1);
    }
}