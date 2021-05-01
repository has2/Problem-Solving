#include <cstdio>
#include <map>
#include <set>
using namespace std;
int N,a[2000];
map<int,int> cnt;
int main(){

    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    set<int> s;
    for(int i=0;i<N-1;i++){
        cnt[a[i]]++;
        for(int j=i+1;j<N;j++) {
            if(a[i]!=0&&a[j]!=0) s.insert(a[i]+a[j]);
        }
    }
    cnt[a[N-1]]++;
    for(auto v : cnt){
        if(v.first==0) {
            if(v.second>2) s.insert(0);
        }else{
            if(cnt.find(0)!=cnt.end() && v.second>1) s.insert(v.first);
        }
    }

    int ans=0;
    for(int i=0;i<N;i++) {
        if(s.find(a[i]) !=s.end()) {
            ans++;
        }
    }
    printf("%d",ans);
}