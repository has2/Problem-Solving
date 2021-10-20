#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N;
int mod=987654321;
bool prime[1000001];
int main(){
    scanf("%d",&N);
    for(int i=2;i<=N;i++){
        for(int j=i*2;j<=N;j+=i){
            prime[j]=1;
        }
    }
    vector<int> primes;
    for(int i=2;i<=N;i++){
        if(!prime[i]) primes.push_back(i);
    }
    ll ret=1;
    for(auto p : primes){
        if(p>N) break;
        ll k = p; 
        while(k*p<=N) k*=p;
        ret=(ret*k)%mod;
    }
    printf("%lld",ret);
}