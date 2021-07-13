#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tc,N,M;
int check[100001][26];
 
void solve(){
    memset(check,0,sizeof(check));
    
    string s,ret;
    for(int i=0;i<N;i++){
        cin >> s;
        for(int j=0;j<M;j++){
            check[j][s[j]-'a']++;
        }
    }
 
    for(int i=0;i<N-1;i++){
        cin >> s;
        for(int j=0;j<M;j++){
            check[j][s[j]-'a']--;
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<26;j++){
            if(check[i][j]>0){
                ret.push_back(j+'a');
            }
        }
    }
    cout << ret << '\n';
    cout << flush;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> tc;
    while(tc--){
        cin >> N >> M;
        solve();
    }
}