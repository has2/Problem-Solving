#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N,mp[500001],pos[100001];
pair<int,int> a[100001];
set<int> ans;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d%d",&a[i].first,&a[i].second);
        ans.insert(a[i].first);
    }
    sort(a,a+N);
    for(int i=0;i<N;i++) mp[a[i].second]=i;

    vector<int> v;
    for(int i=0;i<N;i++){
        int idx = lower_bound(v.begin(),v.end(),a[i].second)-v.begin();
        if(v.size()==idx) v.push_back(a[i].second);
        else v[idx]=a[i].second;
        pos[i]=idx;
    }
    int k=v.size()-1;
    for(int i=N-1;i>=0;i--){
        if(pos[i]==k){
            ans.erase(a[i].first);
            if(--k<0) break;
        }
    }
    printf("%d\n",ans.size());
    for(auto k : ans) printf("%d\n",k);
}