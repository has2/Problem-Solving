#include <cstdio>
#include <string>
using namespace std;
int N;
const int mxN=5e6;
bool np[mxN];
bool check(int n){
    string s = to_string(n);
    int sz = s.size();
    for(int i=0;i<sz/2;i++){
        if(s[i]!=s[sz-1-i]) return 0;
    }
    return 1;
}
int main(){
   scanf("%d",&N);
   np[1]=1;
   for(int i=2;i<mxN;i++){
       if(np[i]) continue;
       for(int j=i+i;j<mxN;j+=i) np[j]=1;
   }
   for(int i=2;i<mxN;i++){
       if(i>=N && !np[i] && check(i)){
           printf("%d",i);
           return 0;
       }
   }
}