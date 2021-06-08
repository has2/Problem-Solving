#include <cstdio>
#include <cstring>
using namespace std;
struct P{
    int x,y,r;
};
int T,N,uf[3000];
bool check[3000];
P a[3000];
int find(int n){
    if(uf[n]==n) return n;
    return find(uf[n]);
}
void merge(int n,int m){
    n=find(n);
    m=find(m);
    uf[n] = m;
}
int adj(int i,int j){
    int d = (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
    return d <= (a[i].r+a[j].r)*(a[i].r+a[j].r);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);

        for(int i=0;i<N;i++) uf[i]=i;

        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                if(adj(i,j)) merge(i,j);
            }
        }
        
        memset(check,0,sizeof(check));
        int ans=0;
        for(int i=0;i<N;i++){
            int p = find(i);
            if(!check[p]){
                ans++;
                check[p]=1;
            }
        }
        printf("%d\n",ans);
    }
}