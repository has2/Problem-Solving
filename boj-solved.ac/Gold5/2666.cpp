#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,a[20],seq[20],ans=9e8;
void sol(int n,int cnt){
    if(n==M){
        ans=min(ans,cnt);
        return;
    }
    int cur = seq[n];
    if(a[cur]){
        sol(n+1,cnt);
    }else{  
        int idx=-1;
        for(int i=cur;i<N;i++){
            if(a[i]){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
            a[cur]=1;
            a[idx]=0;
            sol(n+1,idx-cur+cnt);
            a[cur]=0;
            a[idx]=1;
        }
        idx=-1;

        for(int i=cur;i>=0;i--){
            if(a[i]){
                idx=i;
                break;
            }
        }     
        if(idx!=-1){
            a[cur]=1;
            a[idx]=0;
            sol(n+1,cur-idx+cnt);
            a[cur]=0;
            a[idx]=1;
        }
    }
}
int main(){
    int t1,t2;
    scanf("%d%d%d%d",&N,&t1,&t2,&M);
    a[t1-1]=a[t2-1]=1;
    for(int i=0;i<M;i++){
        int v;
        scanf("%d",&v);
        seq[i]=v-1;
    }
    sol(0,0);
    printf("%d",ans);
}
