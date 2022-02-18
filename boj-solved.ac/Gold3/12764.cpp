#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int N,pos[100001],cnt[100001];
vector<pair<int,int>> v;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int s,e;
        scanf("%d%d",&s,&e);
        v.push_back({s,i});
        v.push_back({e,i});
    }
    set<int> empty,use;
    sort(v.begin(),v.end());
    for(auto [t,i] : v){
        if(pos[i]){
            use.erase(pos[i]);
            empty.insert(pos[i]);
        }else{
            if(empty.size()>0){
                pos[i]=*empty.begin();
                empty.erase(pos[i]);
            }else if(use.size()>0){
                pos[i]=*(--use.end())+1;
            }else{
                pos[i]=1;
            }
            use.insert(pos[i]);
            cnt[pos[i]]++;
        }
    }
    vector<int> ans;
    for(int i=1;;i++){
        if(!cnt[i]) break;
        ans.push_back(cnt[i]);
    }
    printf("%d\n",ans.size());
    for(auto a : ans) printf("%d ",a);
}