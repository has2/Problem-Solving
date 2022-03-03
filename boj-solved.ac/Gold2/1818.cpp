#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,a[200000];
vector<int> v;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    v.push_back(a[0]);
    for(int i=1;i<N;i++){
        auto idx = lower_bound(v.begin(),v.end(),a[i])-v.begin();
        if(idx<v.size()) v[idx]=a[i];
        else v.push_back(a[i]);
    }
    printf("%d",N-v.size());
}