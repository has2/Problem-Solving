#include <cstdio>
#include <set>
using namespace std;
int N,K,a[100],ans;
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++) scanf("%d",&a[i]);

    set<int> s;
    for(int i=0;i<K;i++){
        if(s.find(a[i]) != s.end()) continue;
        if(s.size() < N) s.insert(a[i]);
        else{
            int rm = -1;
            int rmpos = -1;
            for(auto e : s){
                int pos = -1;
                for(int j=i+1;j<K;j++){
                    if(a[j] == e) {
                        pos = j;
                        break;
                    }
                }
                if(pos == -1) {
                    rm = e;
                    break;
                }
                if(rmpos < pos){
                    rmpos = pos;
                    rm = a[pos];
                }
            }
            s.erase(rm);
            s.insert(a[i]);
            ans++;
        }
    }
    printf("%d",ans);
}