#include <algorithm>
#include <cstdio>
using namespace std;
using ll = long long;
int N;
ll M,a[100001];
int main(){
    scanf("%d%lld",&N,&M);
    for(int i=0;i<N;i++) scanf("%lld",&a[i]);
    sort(a,a+N);
    int ans = 2e9;
    for(int i=0;i<N;i++){
        int idx = lower_bound(a+i,a+N,a[i]+M)-a;
        if(idx<N) ans = min(int(a[idx]-a[i]),ans);
    }
    printf("%d",ans);
}