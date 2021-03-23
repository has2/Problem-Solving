#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N,p,q,k=2e9+100;
vector<int> a,b;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        int v;
        scanf("%d",&v);
        if(v>0) a.push_back(v);
        else b.push_back(v);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a.size()>1){
        if(abs(a[0]+a[1]) < k){
            p=a[0];
            q=a[1];
            k=abs(p+q);
        }
    }
    int bsz = b.size();
    if(bsz>1){
        if(abs(b[bsz-2]+b[bsz-1]) < k){
            p=b[bsz-2];
            q=b[bsz-1];
            k=abs(p+q);
        }
    }
    if(!a.empty()){
        for(int v : b){
            int w;
            auto idx = lower_bound(a.begin(),a.end(),-v)-a.begin();
            if(idx>=a.size()){
                w=a[idx-1];
            }else{
                w=a[idx];
                if(idx>0 && abs(w+v) > abs(a[idx-1]+v)) w=a[idx-1];
            }
            if(abs(w+v) < k){
                p=v;
                q=w;
                k=abs(w+v);
            }
        }
    }
    printf("%d %d",p,q);
}