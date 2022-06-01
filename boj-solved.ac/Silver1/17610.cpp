#include <cstdio>
int k,v[14],a[3000000],sum,ans;
void sol(int n,int cur){
    if(cur>=1) {
        if(!a[cur]) ans++;
        a[cur]=1;
    }
    if(n==k) return;
    sol(n+1,cur+v[n]);
    sol(n+1,cur-v[n]);
    sol(n+1,cur);
}
int main(){
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&v[i]);
        sum+=v[i];
    }
    sol(0,0);
    printf("%d",sum-ans);
}