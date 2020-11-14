#include <cstdio>
#include <queue>
#include <functional>
using namespace std;
int K, N, a[100],p,cnt;
int main(){
    scanf("%d%d", &K, &N);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0;i<K;i++){
        scanf("%d", &a[i]);
        pq.push(a[i]);
    }
    while (1){
        int qt = pq.top(); pq.pop();
        if(p>=qt) continue;
        cnt++;
        p = qt;
        if (cnt==N){
            printf("%d", qt);
            return 0;
        }
        for (int i=0;i<K;i++)  {
            if((long long)qt*a[i] <= (long long)1<<31) pq.push(qt * a[i]);
        }
    }
}