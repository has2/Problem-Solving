#include <cstdio>
#include <vector>
using namespace std;
int N;
bool a[1000001];
int main(){
    scanf("%d",&N);
    a[0]=a[1]=1;
    for(int i=2;i<=N;i++){
        for(int j=2*i;j<=N;j+=i) a[j]=1;
    }
    vector<int> ans;
    if(N<8) puts("-1");
    else{
        if(N%2){
            ans.push_back(2);
            ans.push_back(3);
            for(int i=2;i<=N;i++){
                if(!a[i] && !a[N-5-i]){
                    ans.push_back(i);
                    ans.push_back(N-5-i);
                    break;
                }
            }
        }else{
            ans.push_back(2);
            ans.push_back(2);
            for(int i=2;i<=N;i++){
                if(!a[i] && !a[N-4-i]){
                    ans.push_back(i);
                    ans.push_back(N-4-i);
                    break;
                }
            }            
        }
    }
    for(auto p : ans) printf("%d ",p);
}