#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
vector<int> a,b;
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) {
        int v;
        scanf("%d",&v);
        if(v>0) a.push_back(v);
        else b.push_back(-v);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans=0;
    if(!a.empty()){
        for(int i=a.size()%M-1;i<(int)a.size();i+=M){
            if(i>=0) ans+=a[i]*2;
        }
    }
    if(!b.empty()){
        for(int i=b.size()%M-1;i<(int)b.size();i+=M){
            if(i>=0) ans+=b[i]*2;
        }
    }
    if(a.empty()) ans-=b.back();
    else if(b.empty() || a.back()>b.back()) ans-=a.back();
    else ans-=b.back();

    printf("%d",ans);
}