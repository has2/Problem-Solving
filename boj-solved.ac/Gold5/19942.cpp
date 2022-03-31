#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct P{
    int p,f,s,v,c;
};
int N,mp,mf,ms,mv,ansv=9e8;
P a[15];
vector<int> vec,ans;
void sol(int n,int p,int f,int s,int v,int c){
    if(n==N){
        if(p>=mp&&f>=mf&&s>=ms&&v>=mv){
            if(ansv>c){
                ans=vec;
                ansv=c;
            }else if(ansv==c && ans>vec){
                ans=vec;
                ansv=c;                
            }
        }
        return;
    }
    sol(n+1,p,f,s,v,c);
    vec.push_back(n);
    sol(n+1,p+a[n].p,f+a[n].f,s+a[n].s,v+a[n].v,c+a[n].c);
    vec.pop_back();
}
int main(){
    scanf("%d%d%d%d%d",&N,&mp,&mf,&ms,&mv);
    for(int i=0;i<N;i++){
        scanf("%d%d%d%d%d",&a[i].p,&a[i].f,&a[i].s,&a[i].v,&a[i].c);
    }
    sol(0,0,0,0,0,0);
    if(ansv==9e8){
        puts("-1");
        return 0;
    }
    printf("%d\n",ansv);
    for(auto k : ans) printf("%d ",k+1);
}