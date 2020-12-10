#include <cstdio>
#include <algorithm>
std::pair<int,int> v[100000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&v[i].first,&v[i].second);
    sort(v,v+n);
    for(int i=0;i<n;i++) printf("%d %d\n",v[i].first,v[i].second);
}