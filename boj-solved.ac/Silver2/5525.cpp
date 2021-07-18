#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int N,M,ans;
string s,search;
int main(){
    cin >> N >> M >> s;
    for(int i=0;i<N;i++) search+="IO";
    search+="I";
    int start=0;
    while(start<s.size()){
        int idx=s.find(search,start);
        if(idx==string::npos) break;
        int k=1;
        for(start=idx+2*N+1;start<s.size()-1;start+=2){
            if(s[start]=='O'&&s[start+1]=='I') k++;
            else break;
        }
        ans+=k;
    }
    printf("%d",ans);
}