#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int tc;
int n,q,k,a[100003],dp[100003];
 
int main(){
    scanf("%d%d%d",&n,&q,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1]+a[i+1]-a[i-1]-2;
    }
 
    while(q--){
        int l,r,ans=0;
        scanf("%d%d",&l,&r);
        if(l==r) ans=k-1;
        else{
            ans+=a[l+1]-2;
            ans+=k-a[r-1]-1;
            ans+=dp[r-1]-dp[l];
            // for(int i=l;i<=r;i++){
            //     int v;
            //     if(i==l) v = a[i+1]-2;
            //     else if(i==r) v = k-a[i-1]-1;
            //     else v = a[i+1]-a[i-1]-2;
            //     ans+=v;
            // }
        }
        printf("%d\n",ans);
    }
}