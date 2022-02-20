#include <cstdio>
#include <vector>
using namespace std;
int N,visit[1000000],ansn;
vector<int> cur,ans;
void sol(int n,int m){
    if(n!=0&&m==0&&n>ansn){
        ansn=n;
        ans=cur;
        return;
    }
    for(int i=0;i<N;i++){
        if(((1<<i)&m)>0){
            int k=(~(1<<i))&m;
            if((n!=0&&k==0)||!visit[k]){
                visit[k]=1;
                cur.push_back(i);
                sol(n+1,k);
                cur.pop_back();
            }
        }
        if(((1<<i)&m)==0){
            int k=(1<<i)|m;
            if(!visit[k]){
                visit[k]=1;
                cur.push_back(i);
                sol(n+1,k);
                cur.pop_back();
            }
        }
    }
}
int main(){
    scanf("%d",&N);
    sol(0,0);
    printf("%d\n",ansn-1);
    for(auto a : ans) printf("%d ",a+1);
}