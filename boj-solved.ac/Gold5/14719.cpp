#include <cstdio>
#include <algorithm>
using namespace std;
int H,W,a[500];
int getMax(int l,int r){
    int ret=0;
    for(int i=l;i<=r;i++){
        ret=max(a[i],ret);
    }
    return ret;
}
int main(){
    scanf("%d%d",&H,&W);
    for(int i=0;i<W;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<W-1;i++){
        int k = min(getMax(0,i-1),getMax(i+1,W-1));
        if(a[i]<k) ans+=k-a[i];
    }
    printf("%d",ans);
}