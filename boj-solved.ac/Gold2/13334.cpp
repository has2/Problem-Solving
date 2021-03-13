#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,d,ans;
vector<pair<int,int>> t,a;
int main(){
    scanf("%d",&N);
    int j=0;
    for(int i=0;i<N;i++){
        int u,v;  
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        t.push_back({u,v});
    }
    scanf("%d",&d);

    for(auto p : t){
        if(p.second-p.first>d) continue;
        a.push_back({p.first,1});
        a.push_back({p.second-d,-1});
    }
    sort(a.begin(),a.end());
    int cnt=0;
    for(auto p : a){       
        cnt-=p.second;
        ans=max(ans,cnt);
    }
    printf("%d",ans);
}