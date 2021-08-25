#include <vector>
#include <algorithm>
using namespace std;
int N,answer;
int solution(vector<int> cookie) {
    N=cookie.size();
    cookie.insert(cookie.begin(),0);
    vector<int> sum(N+1);
    for(int i=1;i<=N;i++) sum[i]=sum[i-1]+cookie[i];
    for(int i=1;i<=N-1;i++){
        for(int j=i;j<=N-1;j++){
            int t = 2*sum[j]-sum[i-1];
            int idx = lower_bound(sum.begin(),sum.end(),t)-sum.begin();
            if(idx<=N && sum[idx]==t) answer=max(sum[j]-sum[i-1],answer);
        }  
    }
    return answer;
}