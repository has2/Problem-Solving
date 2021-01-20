#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,uf[1001];
bool check[1001];
struct P{
    int u,v,d;
};
vector<P> vec;
int find(int a){
    if(a==uf[a]) return a;
    return uf[a]=find(uf[a]);
}
bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return 0;
    uf[a]=b;
    return 1;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) {
        char a;
        scanf(" %c",&a);
        check[i]=a=='M';
    }
    while(M--){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        if(check[u]!=check[v]) vec.push_back({u,v,d});
    }
    sort(vec.begin(),vec.end(),[](P& a,P& b)->bool{
        return a.d<b.d;
    });
    for(int i=1;i<=N;i++) uf[i]=i;

    int ans=0,cnt=0;
    for(int i=0;i<vec.size();i++){
        if(merge(vec[i].u,vec[i].v)){
            ans+=vec[i].d;
            if(++cnt==N-1){
                printf("%d",ans);
                return 0;
            }
        }
    }
    puts("-1");
}