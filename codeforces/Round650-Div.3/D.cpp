#include <string>
#include <queue>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int tc,n,k,b[51],cnt[27];
int main(){
    scanf("%d",&tc);
    while(tc--){
        string s;
        cin >> s >> n;
        for(int i=0;i<n;i++) cin >> b[i];
        priority_queue<int> q;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<s.size();i++){
            if(!cnt[s[i]-'a']) q.push(s[i]-'a');
            cnt[s[i]-'a']++;
        }
        string ans;
        ans.resize(n);
        int total=0;
        while(total<n){
            vector<int> t;
            for(int i=0;i<n;i++) {
                if(b[i]==0) {
                    b[i]=-1;
                    t.push_back(i);
                }
            }
            for(int i=0;i<n;i++) {
                if(b[i]==-1) continue; 
                for(auto k : t) b[i]-=abs(i-k);
            }
            while(!q.empty()){
                if(cnt[q.top()]>=t.size()){
                    for(auto k : t) ans[k]=q.top()+'a';
                    q.pop();
                    total+=t.size();
                    break;
                }
                q.pop();
            }
        }
        cout << ans << '\n';
    }
}
