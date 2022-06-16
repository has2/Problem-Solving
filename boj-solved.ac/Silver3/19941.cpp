#include <iostream>
#include <string>
using namespace std;
int N,K,ans;
string s;
int main(){
    cin >> N >> K >> s;
    for(int i=0;i<N;i++){
        if(s[i]=='P'){
            for(int j=i-K;j<=i+K && j<N;j++){
                if(j<0) continue;
                if(s[j]=='H'){
                    ans++;
                    s[j]='O';
                    break;
                }
            }
        }
    }
    printf("%d",ans);
}