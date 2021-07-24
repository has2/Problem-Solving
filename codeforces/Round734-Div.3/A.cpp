#include <cstdio>
using namespace std;
int tc,n,a,b;
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        int k = n/3;
        int mod = n%3;
        
        a=b=k;
        if(mod==1){
            a++;
        }else if(mod==2){
            b++;
        }
        printf("%d %d\n",a,b);
    }
}