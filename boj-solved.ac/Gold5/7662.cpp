#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int T,k;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&k);
        char cmd;
        int v;
        multiset<int> ms;
        while(k--){
            scanf(" %c %d",&cmd,&v);
            if(cmd=='I'){
                ms.insert(v);
            }else if(!ms.empty()){
                ms.erase(v==1? --ms.end() : ms.begin());
            }
        }
        if(ms.empty()) puts("EMPTY");
        else printf("%d %d\n",*(--ms.end()),*ms.begin());
    }
}