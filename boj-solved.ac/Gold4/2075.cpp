#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int N;
int main(){
    priority_queue<int,vector<int>,greater<int>> a;
    scanf("%d",&N);
    for(int i=0;i<N*N;i++) {
        int v;
        scanf("%d",&v);
        if(a.size()<N) a.push(v);
        else if(a.top() < v) {
            a.pop();
            a.push(v);
        }
    }
    printf("%d",a.top());
}