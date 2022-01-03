#include <cstdio>
#include <algorithm>
using namespace std;
int D,N,a[300001];
int main(){
    scanf("%d%d",&D,&N);
    for(int i=0;i<=D;i++) a[i]=2e9;
    for(int i=1;i<=D;i++) {
        int v;
        scanf("%d",&v);
        a[i] = min(v,a[i-1]);
    }
    int cur=D, ans=0;
    while(N--){
        int v;
        scanf("%d",&v);
        for(;cur>=0;cur--){
            if(v<=a[cur]){
                ans=cur;
                cur--;
                break;
            }    
        }
    }
    printf("%d",ans);
}