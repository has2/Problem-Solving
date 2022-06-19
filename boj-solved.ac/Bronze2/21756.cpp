#include <cstdio>
#include <vector>
using namespace std;
int N;
vector<int> v1,v2;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) v1.push_back(i);
    while(v1.size()!=1){
        v2.clear();
        for(int i=1;i<v1.size();i+=2) v2.push_back(v1[i]);
        v1=v2;
    }
    printf("%d",v1.front());
}