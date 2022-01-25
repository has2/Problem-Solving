#include <cstdio>
#include <algorithm>
using namespace std;
int N,K,a[300000],ans;
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    sort(a,a+N);
    ans = a[N-1]-a[0];
    for(int i=N-1;i>=1;i--) a[i]=a[i]-a[i-1];
    a[0]=0;
    sort(a,a+N);
    for(int i=N-1;K>1;K--,i--) ans-=a[i];
    printf("%d",ans);
}