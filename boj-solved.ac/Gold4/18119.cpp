#include <iostream>
#include <string>
using namespace std;
int N,M,a[10001];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(auto c : s) a[i] |= 1<<(c-'a');
    }
    int cur = (1<<26)-1;
    while(M--){
        int o,cnt=0;
        char x;
        cin >> o >> x;
        if(o==1) cur ^= 1<<(x-'a');
        else cur |= 1<<(x-'a');
        
        for(int i=0;i<N;i++){
            if(a[i] == (a[i]&cur)) cnt++;
        }
        cout << cnt << '\n';
    }
}