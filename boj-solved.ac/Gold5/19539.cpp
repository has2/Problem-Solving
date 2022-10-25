#include <cstdio>
int N,a[100000],sum,cnt;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
        cnt+=a[i]/2;
    }
    if(sum%3||cnt<sum/3) {
        puts("NO");
        return 0;
    }
    puts("YES");
}