#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,a[5001];
bool check(int m){
    int cnt=0;
    int minv=a[0],maxv=a[0];
    for(int i=0;i<=N;i++){
        minv=min(minv,a[i]);
        maxv=max(maxv,a[i]);

        int diff = maxv-minv;
        if(diff<=m) continue;
        cnt++;

        minv=maxv=a[i];
    }
    return cnt<=M;
}
int sol(){
    int lo=-1,hi=10000;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    return hi;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    a[N]=1e5;
    printf("%d",sol());
}