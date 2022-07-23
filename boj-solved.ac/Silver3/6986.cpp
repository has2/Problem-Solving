#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int N,K;
double a[100001];
int main(){
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++) scanf("%lf",&a[i]);
    sort(a+1,a+N+1);
    double sum=0;
    for(int i=K+1;i<=N-K;i++){
        sum+=a[i];
    }
    double t = sum / (N-2*K);
    printf("%.2lf\n",floor(t*100+0.5)/100);
    for(int i=1;i<=K;i++){
        a[i]=a[K+1];
        a[N-i+1] = a[N-K];
    }
    sum=0;
    for(int i=1;i<=N;i++) sum+=a[i];
    t = sum / N;
    printf("%.2lf",floor(t*100+0.5)/100);    
}