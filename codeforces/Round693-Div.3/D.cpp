#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int tc,N;
int main(){
    scanf("%d",&tc);
    
    while(tc--){
        scanf("%d",&N);
        vector<ll> odd,even;
        for(int i=0;i<N;i++){
            ll v;
            scanf("%lld",&v);
            if(v%2) odd.push_back(v);
            else even.push_back(v);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        
        int curo=odd.size()-1,cure=even.size()-1;
        ll alice=0,bob=0;
        for(int i=0;;i++){
            if(curo<0&&cure<0) break;
            if(i%2==0){
                if(curo<0){
                    alice+=even[cure--];
                    continue;
                }
                if(cure<0){
                    curo--;
                    continue;
                }

                if(odd[curo] <= even[cure]){
                    alice+=even[cure--];
                }else{
                    curo--;
                }
            }else{
                if(curo<0){
                    cure--;
                    continue;
                }
                if(cure<0){
                    bob+=odd[curo--];
                    continue;
                }

                if(odd[curo] >= even[cure]){
                    bob+=odd[curo--];
                }else{
                    cure--;
                }
            }
        }
        if(alice>bob) puts("Alice");
        else if(alice<bob) puts("Bob");
        else puts("Tie");
        //printf("alice:%d, bob:%d\n",alice,bob);
    }
}