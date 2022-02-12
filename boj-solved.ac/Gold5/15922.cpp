#include <cstdio>
#include <algorithm>
using namespace std;
int N;
pair<int,int> v[100000];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d",&v[i].first,&v[i].second);
    sort(v,v+N);
    int ans=0,s=v[0].first,e=v[0].second;
    for(int i=0;i<N;i++){
        if(v[i].first <= e) {
            if(v[i].second > e) e=v[i].second;
        }else{
            ans+=e-s;
            s=v[i].first;
            e=v[i].second;
        }
    }
    printf("%d",ans+e-s);
}