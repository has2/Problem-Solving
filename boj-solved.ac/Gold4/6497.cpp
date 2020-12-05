#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int mx = 2e5;
int N,M,uf[mx];
struct P{
    int a,b,c;
};
vector<P> v;
bool cmp(P& a,P& b){
    return a.c < b.c;
}
int find(int a){
    if(a==uf[a]) return a;
    return uf[a] = find(uf[a]);
}
bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return 0;
    uf[a] = b;
    return 1;
}

int main(){
    while(1){
        int t=0;
        v.clear();
        scanf("%d%d",&N,&M);
        if(N==0&&M==0) return 0;
        for(int i=0;i<M;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            t+=c;
            v.push_back({a,b,c});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<N;i++) uf[i]=i;
        int ans =0,cnt=0;
        for(int i=0;i<v.size();i++){
            if(merge(v[i].a,v[i].b)){
                ans+=v[i].c;
                if(++cnt==N-1) break;
            }
        }
        printf("%d\n",t-ans);
    }
}
    
