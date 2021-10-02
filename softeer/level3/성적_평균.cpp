#include <cstdio>
#include <cmath>
using namespace std;
int N,K,sum[1000001];
int main(){
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++) {
        int v;
        scanf("%d",&v);
        sum[i]=sum[i-1]+v;
    }
    while(K--){
        int a,b;
        scanf("%d%d",&a,&b);
        double ans = (double)(sum[b]-sum[a-1])/(b-a+1);
        ans=ceil(ans*100)/100;
        printf("%.2f\n",ans);
    }
}