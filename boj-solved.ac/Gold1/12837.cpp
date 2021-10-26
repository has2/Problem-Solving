#include <cstdio>
using namespace std;
using ll = long long;
int N,Q,sidx;
ll segTree[3000000];

ll sum(int L,int R,int node,int cL,int cR){
    if(cR<L || R<cL) return 0;
    if(L<=cL && cR<=R) return segTree[node];
    int mid = (cL+cR)/2;
    return sum(L,R,2*node,cL,mid) + sum(L,R,2*node+1,mid+1,cR);
}

void update(int i,int v){
    i+=sidx;
    while(i>0){
        segTree[i]+=v;
        i/=2;
    }
}

int main(){
    scanf("%d%d",&N,&Q);
    for(sidx=1;sidx<N;sidx*=2);
    while(Q--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1){
            update(b-1,c);
        }else{
            printf("%lld\n",sum(b-1,c-1,1,0,sidx-1));
        }
    }
}