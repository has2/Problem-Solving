#include <cstdio>
int n,m,a[100000];
bool check(int k){
    int cnt=1,sum=0;
    for(int i=0;i<n;i++){
        if(sum+a[i]>k) {
            sum=0;
            cnt++;
        }
        sum+=a[i];
    }
    return cnt <= m;
}
int main(){
    scanf("%d%d",&n,&m);
    int lo=1,hi=1e9+1;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if(a[i]>lo) lo=a[i];
    }
    lo--;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    printf("%d",lo+1);
}