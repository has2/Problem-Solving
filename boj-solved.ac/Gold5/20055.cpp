#include <cstdio>
using namespace std;
int N,K,robot[101],belt[201];
int main(){
    scanf("%d%d",&N,&K);
    for(int i=1;i<=2*N;i++) scanf("%d",&belt[i]);
    int ret=1;
    while(1){
        for(int i=N;i>=2;i--) robot[i]=robot[i-1];
        robot[1]=robot[N]=0;
        int t = belt[2*N];
        for(int i=2*N;i>=2;i--) belt[i]=belt[i-1];
        belt[1]=t;

        for(int i=N-1;i>=2;i--) {
            if(robot[i] && !robot[i+1] && belt[i+1]>=1) {
                belt[i+1]--;
                robot[i]=0;
                if(i+1!=N) robot[i+1]=1;
            }
        } 
        if(belt[1]>0) {
            robot[1]=1;
            belt[1]--;
        }
        int cnt=0;
        for(int i=1;i<=2*N;i++) if(belt[i]==0) cnt++;
        
        if(cnt>=K) break;
        ret++;
    }
    printf("%d",ret);
}