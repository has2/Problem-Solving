#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
 
int tc,N;
string me,enemy;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> N >> enemy >> me;
        
        int ans=0;
        for(int i=0;i<N;i++){
            if(enemy[i]=='0' && me[i]=='1'){
                ans++;
                me[i]='0';
            }
        }
 
        for(int i=0;i<N;i++){
            if(me[i]=='0') continue;
            if(i!=0 && enemy[i-1]=='1'){
                ans++;
                continue;
            }
            if(i!=N-1 && enemy[i+1]=='1'){
                ans++;
                enemy[i+1]='0';
            }
        }
        cout << ans << '\n';
    }
}