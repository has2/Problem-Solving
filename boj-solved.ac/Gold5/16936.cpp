#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;
using ll = long long;
int N;
ll B[101];
map<ll,int> m;
vector<int> adj[101];
bool sol(int n,string s,int dep){
    if(dep==N-1){
        printf("%s",s.c_str());
        return true;
    }
    for(auto nxt : adj[n]) if(sol(nxt,s+" "+to_string(B[nxt]),dep+1)) return true;
    return false;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%lld",&B[i]);
        m[B[i]]=i;
    }
    for(int i=0;i<N;i++){
        if(m.find(B[i]*3) != m.end()) adj[m[B[i]*3]].push_back(i);   
        if(B[i]%2==0 && m.find(B[i]/2) != m.end()) adj[m[B[i]/2]].push_back(i);
    }
    for(int i=0;i<N;i++) if(sol(i,to_string(B[i]),0)) return 0;
}