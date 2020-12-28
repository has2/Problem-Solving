#include <algorithm>
#include <cstdio>
int N,a[100000];
bool d[2001];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    std::sort(a,a+N);
    for(int i=0;i<N;i++){
        if(!d[a[i]+1000]){
            d[a[i]+1000]=1;
            printf("%d ",a[i]);
        }
    }
}