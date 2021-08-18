#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
const int mxN=5e5;
int cnt[mxN],idx[mxN],ans;
int solution(std::vector<int> a) {
    memset(idx,-1,sizeof(idx));
    for(int i=0;i<a.size();i++){
        if(i<=idx[a[i]]) continue;
        if(i>0&& idx[a[i]] < i-1 && a[i]!=a[i-1]){
            cnt[a[i]]++, idx[a[i]]=i;
            continue;
        }
        int j=i;
        while(++j<a.size() && a[j] == a[i]);
        if(j<a.size()) cnt[a[i]]++, idx[a[i]]=j;
    }
    for(int i=0;i<a.size();i++) ans=std::max(ans,cnt[i]);
    return ans*2;
}