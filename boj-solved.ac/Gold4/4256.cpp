#include <cstdio>
int tc,N,pre[1001],in[1001];
void post(int lp,int rp,int li,int ri){
    if(lp>rp) return;
    if(lp==rp) {
        printf("%d ",pre[lp]);
        return;
    }

    int root = pre[lp];
    int idx=li;

    for(int i=li;i<=ri;i++){
        if(root==in[i]){
            idx=i;
            break;
        }
    }
    int lcnt = idx-li;

    post(lp+1,lp+lcnt,li,idx-1);
    post(lp+lcnt+1,rp,idx+1,ri);
    printf("%d ",pre[lp]);
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",&pre[i]);
        for(int i=0;i<N;i++) scanf("%d",&in[i]);
        post(0,N-1,0,N-1);
        puts("");
    }
}