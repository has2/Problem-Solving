#include <iostream>
#include <string>
using namespace std;
string w,s;
int N,M,wcnt[100],scnt[100],ans;
int main(){
    cin >> N>>M>>w>>s;
    for(auto c : w) wcnt[c-'A']++;
    int sidx=0;
    for(int i=0;i<M;i++){
        char c = s[i];
        if(scnt[c-'A'] < wcnt[c-'A']){
            scnt[c-'A']++;
        }else{
            for(int j=sidx;j<=i;j++){
                if(s[i]==s[j]){
                    sidx=j+1;
                    break;
                }
                scnt[s[j]-'A']--;
            }
        }
        if(i-sidx+1==N) ans++;
    }
    printf("%d",ans);
}