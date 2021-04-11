#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int N;
bool prime(int n){
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) return 0;
    return 1;
}
int main(){
    scanf("%d",&N);
    vector<int> prev,cur;
    prev = {2,3,5,7};
    cur=prev;
    for(int i=1;i<N;i++){   
        cur.clear();
        for(int v : prev) {
            for(int j=1;j<10;j+=2){
                int a = v*10+j;
                if(prime(a)) cur.push_back(a);
            }
        }
        prev=cur;
    }
    for(auto a : cur) printf("%d\n",a);
}