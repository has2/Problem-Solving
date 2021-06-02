#include <cstdio>
#include <algorithm>
using namespace std;
int N,K,a[10000];
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    sort(a,a+N);
    int ans = a[N-1]-a[0];
    for(int i=1;i<N;i++) a[i-1] = a[i]-a[i-1]; 
    sort(a,a+N-1);
    for(int i=N-2;i>=N-K && i>=0 ;i--) ans-=a[i];
    printf("%d",ans);
}