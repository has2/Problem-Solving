#include <cstdio>
#include <vector>
using namespace std;
int N,root,del;
vector<int> child[50];
int trvs(int n){
    if(n==del) return 0;
    if(child[n].empty()) return 1;
    int ret=0;
    bool f = 0;
    for(auto c : child[n]) {
        if(c==del) f=1;
        else ret+=trvs(c);
    }
    if(f && ret==0) return 1;
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int par;
        scanf("%d",&par);
        if(par!=-1) child[par].push_back(i);
        else root=i;
    }
    scanf("%d",&del);   
    printf("%d",trvs(root));
}