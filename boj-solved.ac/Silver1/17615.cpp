#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<pair<char,int>> v; 
int N;
string s;
int main(){
    cin >> N >> s;
    for(int i=0;i<s.size();i++){
        int j=i;
        int cnt=0;
        for(;j<s.size();j++){
            if(s[i]==s[j]) cnt++;
            else break;
        }
        v.push_back({s[i],cnt});
        i=j-1;
    }
    int ans,rtmp=0,btmp=0;
    for(int i=1;i<v.size();i++){
        auto [col,cnt] = v[i];
        if(col=='R') rtmp+=cnt;
        else btmp+=cnt;
    }
    ans=min(rtmp,btmp);
    rtmp=0,btmp=0;
    for(int i=v.size()-2;i>=0;i--){
        auto [col,cnt] = v[i];
        if(col=='R') rtmp+=cnt;
        else btmp+=cnt;
    }
    ans=min(ans,btmp);
    ans=min(ans,rtmp);
    printf("%d",ans);
}