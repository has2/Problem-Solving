#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct eg{
    int c,a,b;
};
vector<eg> v;
int N,M,uf[100001],cnt,ans;
bool cmp(eg& a,eg& b){
    return a.c < b.c;
}
int find(int a){
    if(a==uf[a]) return a;
    return uf[a] = find(uf[a]);
}
bool merge(int a,int b){
    int pa = find(a);
    int pb = find(b);
    if(pa==pb) return 0;
    uf[pa] = find(pb);
    return 1;
}
int main(){
    scanf("%d%d",&N,&M);
    v.resize(M);
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].c);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=N;i++) uf[i] = i;
    for(int i=0;;i++){
        if(merge(v[i].a,v[i].b)){
            if(++cnt==N-1) break;
            ans+=v[i].c;
        }
    }
    printf("%d",ans);
}