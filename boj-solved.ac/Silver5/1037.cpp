#include <cstdio>
#include <algorithm>
int main(){
    int n,a[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    std::sort(a,a+n);
    printf("%lld",(long long)a[0]*a[n-1]);
}