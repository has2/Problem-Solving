#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
pair<int,int> a[5001];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+M);
    int s=a[0].first,e=a[0].second,cnt=0;
    for(int i=1;i<M;i++){
        if(a[i].first > e) {
            cnt+=e-s;
            s=a[i].first, e=a[i].second;
        }else{
            e=max(e,a[i].second);
        }
    }
    cnt+=e-s;
    printf("%d",N-cnt);
}