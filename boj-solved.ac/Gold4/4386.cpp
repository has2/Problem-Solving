#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct eg{
    int a,b;
    double cost;
};
vector<eg> v;
int N,uf[100];
double x[100],y[100];

bool cmp(eg& a,eg& b){
    return a.cost < b.cost;
}

int find(int a){
    if(a==uf[a]) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return 0;
    uf[a] = b;
    return 1;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            double dist = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            v.push_back({i,j,dist});
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<N;i++) uf[i] = i;
    int cnt = 0;
    double ans = 0;
    for(int i=0;;i++){
        if(merge(v[i].a,v[i].b)){
            ans+=v[i].cost;
            if(++cnt==N-1) break;
        }
    }
    printf("%f",ans);
}