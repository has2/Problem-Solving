#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int tc,n;
string arr[200001];
 
int getCnt(char target){
    int total_diff=0;
 
    vector<int> diff; // diff
    for(int i=0;i<n;i++){
        int cnt=0;
        for(char c : arr[i]){
            if(c==target){
                cnt++;
            }
        }
        int other = (int)arr[i].size()-cnt;
        diff.push_back(cnt-other);
        total_diff+=(cnt-other);
    }
    sort(diff.begin(),diff.end());
    for(int i=0;i<diff.size();i++){
        if(total_diff>0) {
            return n-i;
        }
        total_diff -= diff[i];
    }
    return 0;
}
 
void solve(){
    int ret=0;
    for(int i=0;i<5;i++){
        ret=max(ret,getCnt('a'+i));
    }
    cout <<ret<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> tc;
    while(tc--){
        cin >> n; 
        for(int i=0;i<n;i++) cin >> arr[i];
        solve();
    }
}