#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,L,a[102];
int check(int d){
    int ret=0;
    for(int i=1;i<=N+1;i++){
        int diff = a[i]-a[i-1];
        if(diff>d){
            if(diff%d==0) ret+=diff/d-1;
            else ret+=diff/d;
        }
    }
    return ret;
}
int main(){
    scanf("%d%d%d",&N,&M,&L);
    a[0]=0;
    a[N+1]=L;
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    sort(a,a+N+2);
    int l=0;
    int r=L;
    while(l+1<r){
        int mid = (l+r)/2;
        int cnt = check(mid);
        if(M<cnt) l=mid;
        else r=mid;
    }
    printf("%d",r);
}