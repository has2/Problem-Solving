#include <cstdio>
#include <string>
using namespace std;
int N,ans;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        auto s = to_string(i);
        int sum=0;
        for(auto c : s) sum+=c-'0';
        if(i%sum==0) ans++;
    }
    printf("%d",ans);
}