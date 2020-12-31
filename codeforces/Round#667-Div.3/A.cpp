// #667 div3 A
#include <cstdio>
#include <cmath>
using namespace std;
int tc,a,b;
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&a,&b);
        int d = abs(a-b);
        printf("%d\n",d/10+(d%10!=0));
    }
}
