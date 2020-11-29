#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
using vv = vector<vector<ll>>;
int N;
ll B,mod=1000;
struct A{
    vv arr;
    A(){};
    A(vv arr):arr(arr){};
    A operator*(A& a){
        vv tmp = arr;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                tmp[i][j]=0;
                for(int k=0;k<N;k++){
                    tmp[i][j] += arr[i][k]*a.arr[k][j];
                    tmp[i][j]%=mod;
                }
            }
        }
        return A(tmp);
    }
};
A base;
void print(A& a){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%lld ",a.arr[i][j]);
        }
        puts("");
    }
}
A sol(ll n){
    if(n==1) return base;
    A u = sol(n/2);
    u=u*u;
    if(n%2) u=u*base;
    return u;
}
int main(){
    scanf("%d%lld",&N,&B);
    vv v;
    v.resize(N);
    for(int i=0;i<N;i++){
        ll t;
        for(int j=0;j<N;j++){
            scanf("%lld",&t);
            v[i].push_back(t%mod);
        }
    }
    base = A(v);
    A ret = sol(B);
    print(ret);
}