#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,v;
    vector<int> a;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&v);
        if(a.empty()) a.push_back(v);
        else {
            if(a.back()<v) a.push_back(v);
            else *lower_bound(a.begin(),a.end(),v)=v;
        }
    }
    printf("%d",a.size());
}