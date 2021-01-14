#include <cstdio>
#include <algorithm>
using namespace std;
int N,L,R,X,a[15],ans;
int main(){
    scanf("%d%d%d%d",&N,&L,&R,&X);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=1;i<(1<<N);i++){
        int ml=2e9,mr=0,sum=0,cnt=0;
        for(int j=0;j<N;j++){
            if((i&(1<<j))>0){
                mr=max(mr,a[j]);
                ml=min(ml,a[j]);
                sum+=a[j];
                cnt++;
            }
        }
        if(cnt>=2 && sum<=R&&sum>=L&&mr-ml>=X) ans++;
    }
    printf("%d",ans);
}
