#include <cstdio>
#include <vector>
using namespace std;
int N;
vector<int> ans;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        vector<int> tmp;
        tmp.push_back(N);
        tmp.push_back(i);
        for(int j=1;;j++){
            if(tmp[j-1]-tmp[j]<0) break;
            tmp.push_back(tmp[j-1]-tmp[j]);
        }
        if(tmp.size()>ans.size()) ans=tmp;
    }
    printf("%d\n",ans.size());
    for(auto v : ans) printf("%d ",v);
}