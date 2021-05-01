#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N,Q;
struct P{
    int x1,x2,num;
};
bool cmp(P a,P b){
    return a.x1 < b.x1;
}
P tree[100001];
int g[100001];
int main(){
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        tree[i]={a,b,i};
    }
    sort(tree,tree+N,cmp);

    int sid=0,e=tree[0].x2;
    g[0]=sid;

    for(int i=1;i<N;i++){
        if(tree[i].x1<=e){
            if(tree[i].x2>e) e=tree[i].x2;    
        }else{
            sid++;
            e=tree[i].x2;
        }
        g[tree[i].num]=sid;
    }
    while(Q--){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        if(g[u]==g[v]) puts("1");
        else puts("0");
    }
}