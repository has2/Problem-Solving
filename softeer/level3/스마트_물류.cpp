#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N,K;
vector<int> p;
queue<int> q;
string s;
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) {
        char c;
        scanf(" %c",&c);
        if(c=='P') p.push_back(i);
        else q.push(i);
    }
    int ans=0;
    for(auto r : p){
        while(!q.empty()){
            int i = q.front(); 
            if(abs(r-i)<=K) {
                ans++;
                q.pop();
                break;
            }else if(r>i) q.pop();
            else break;
        }
    }
    printf("%d",ans);
}