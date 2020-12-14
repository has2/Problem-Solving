#include <cstdio>
#include <algorithm>
using namespace std;
int N,K,a[5000000];
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    sort(a,a+N);
    printf("%d",a[K-1]);
}