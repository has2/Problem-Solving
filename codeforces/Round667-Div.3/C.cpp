// #667 div3 C
#include <cstdio>
using namespace std;
int n,x,y,tc;
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&x,&y);
        int s,e,j;
        for(int i=1;;i++){
            int cnt=1;
            j=i;
            if((y-x)%i) continue;
            s=x,e=y;
            cnt+=(y-x)/i;
            if(cnt > n) continue;
            if(cnt == n) break;
            s -= ((x-1)/i)*i;
            if((x-1)/i+cnt>=n) {
                cnt+=(x-1)/i;
                s+=(cnt-n)*i;
                break;
            }
            cnt+=(x-1)/i;
            e+=(n-cnt)*i;
            break;
        }
        for(int i=s;i<=e;i+=j) printf("%d ",i);
        puts("");
    }
}
