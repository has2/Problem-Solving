#include <string>
#include <vector>
using namespace std;
char mp[5] = {'A','E','I','O','U'};
int ans;
int sol(string str,string& word){
    ans++;
    if(str==word) return ans-1;
    if(str.size()>=5) return 0;
    for(int i=0;i<5;i++) {
        int ret=sol(str+mp[i],word);
        if(ret) return ret;
    }
    return 0;
}
int solution(string word) {
    return sol("",word);
}
