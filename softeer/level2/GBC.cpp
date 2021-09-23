#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,u,v,ans;
int main(){
    scanf("%d%d",&N,&M);
    vector<int> a,b;
    while(N--){
        scanf("%d%d",&u,&v);
        while(u--) a.push_back(v);
    }
    while(M--){
        scanf("%d%d",&u,&v);
        while(u--) b.push_back(v);        
    }
    for(int i=0;i<100;i++) ans=max(ans,b[i]-a[i]);
    printf("%d",ans);
}