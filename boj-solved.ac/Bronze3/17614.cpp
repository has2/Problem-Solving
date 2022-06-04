#include <cstdio>
#include <string>
using namespace std;
int N,ans;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        string s = to_string(i);
        for(auto c : s) {
            if(c=='3' || c=='6'||c=='9') ans++;
        }
    }
    printf("%d",ans);
}