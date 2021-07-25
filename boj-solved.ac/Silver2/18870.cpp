#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int mxN = 1e6+1;
int n,a[mxN],b[mxN],k;
map<int,int> mp;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) mp[a[i]]= mp.find(a[i])==mp.end() ? ++k : k;
    for(int i=0;i<n;i++) printf("%d ",mp[b[i]]-1);
}