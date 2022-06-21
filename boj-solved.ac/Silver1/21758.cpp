#include <cstdio>
#include <algorithm>
using namespace std;
int N,sum[100001],a[100001],ans;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=2;i<N;i++) {
        ans=max(ans,2*sum[N]-a[1]-a[i]-sum[i]);
        ans=max(ans,sum[N-1]-a[i]+sum[i-1]);
        ans=max(ans,sum[i]-a[1]+sum[N-1]-sum[i-1]);
    }
    printf("%d",ans);
}