#include <cstdio>
using ll = long long;
int T,f[1000001];
ll s[1000001];
int main(){
    scanf("%d",&T);
    for(int i=1;i<=1e6;i++)
        for(int j=i;j<=1e6;j+=i) f[j]+=i;
    for(int i=1;i<=1e6;i++) s[i]=f[i]+s[i-1]; 
    while(T--){
        int v;
        scanf("%d",&v);
        printf("%lld\n",s[v]);
    }
}