#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N,a[26],ans,v,start;
string s;
int main(){
    cin >> N >> s;
    string cur;
    for(int i=0;i<s.size();i++){
        int cnt=0;
        for(int j=0;j<26;j++) {
            if(a[j]>0) cnt++;
        }
        if(cnt<N || a[s[i]-'a']){
            v++;
            a[s[i]-'a']++;
            ans=max(ans,v);
            continue;
        }
        for(int j=start;j<=i;j++){
            v--;
            if(--a[s[j]-'a'] == 0){
                start=j+1;
                break;
            }
        }
        i--;
    }
    printf("%d",ans);
}