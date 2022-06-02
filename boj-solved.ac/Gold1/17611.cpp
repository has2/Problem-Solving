#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,ans;
pair<int,int> p[100000];
vector<pair<int,int>> a[2];
int main(){ 
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&p[i].first,&p[i].second);
    for(int i=1;i<=n;i++){
        int l,r,q=i,z=i-1;
        if(q==n) q=n-1,z=0;
        if(p[q].first==p[z].first) {
            l=min(p[q].second,p[z].second);
            r=max(p[q].second,p[z].second);
        }else{
            l=min(p[q].first,p[z].first);
            r=max(p[q].first,p[z].first);            
        }
        a[i%2].push_back({l,1});
        a[i%2].push_back({r,-1});
    }
    for(int i=0;i<2;i++){
        sort(a[i].begin(),a[i].end());
        int tmp=0;
        for(auto [t,v] : a[i]){
            tmp+=v;
            ans=max(tmp,ans);
        }
    }
    printf("%d",ans);
}