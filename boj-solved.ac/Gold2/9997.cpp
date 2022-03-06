#include <iostream>
#include <string>
using namespace std;
int N,ans,a[25];
void sol(int n,int b){
    if(n==N) {
        if(b==(1<<26)-1) ans++;
        return;
    }
    sol(n+1,b);
    sol(n+1,b|a[n]);
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        string s;
        cin >> s;
        int b=0;
        for(auto c : s) b |= (1<<(c-'a'));
        a[i]=b;
    }
    sol(0,0);
    cout << ans;
}