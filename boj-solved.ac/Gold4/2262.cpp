#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,ans;
int main(){
    scanf("%d",&N);
    vector<int> v(N);
    for(int i=0;i<N;i++) scanf("%d",&v[i]);
    while(v.size()>1){
        int idx = max_element(v.begin(),v.end())-v.begin();
        int l=0,r=0;
        if(idx-1>=0) l=v[idx-1];
        if(idx+1<v.size()) r=v[idx+1];
        ans+=v[idx]-max(l,r);
        vector<int> tmp;
        for(auto c : v){
            if(c!=v[idx]) tmp.push_back(c);
        }
        v=tmp;
    }
    printf("%d",ans);
}