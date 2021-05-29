#include <cstdio>
#include <string>
using namespace std;
int N,K;
int check(int m){
    int ret=0;
    int k=1;
    int i=10;
    for(;i<=m;i*=10,k++) ret+=(i-i/10)*k;
    ret+=k*(1+m-i/10);
    return ret;
}
int main(){
    scanf("%d%d",&N,&K);
    int lo=1;
    int hi=N+1;
    int cnt;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(check(mid)<=K) lo=mid;
        else hi=mid;
    }
    cnt = check(lo);
    if(cnt==K) printf("%c",to_string(lo).back());
    else {
        int r = K-cnt;
        string h;
        if(lo==N || to_string(hi).size() < r) {
            puts("-1");
            return 0;
        }
        printf("%c",to_string(hi)[r-1]);
    }
}