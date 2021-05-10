#include <cstdio>
#include <iostream>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
int tc,N;
ll A,B;
 
void solve(){
    if(B==1) {
        puts("NO");
        return;
    }
    puts("YES");
    if(B==2){
        printf("%lld %lld %lld\n",2*A,A,3*A);
        return;
    }
    ll r1,r2;
    for(int i=1;;i++){
        r1=i;
        r2=B-i;
        if(r1!=r2) break;
    }
    printf("%lld %lld %lld\n",r1*A,r2*A,A*B);
    //B=A+B-A
}
 
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&A,&B);
        solve();
    }
}