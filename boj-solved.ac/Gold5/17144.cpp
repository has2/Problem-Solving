#include <cstdio>
#include <vector>
using namespace std;
using vvi = vector<vector<int>>;
int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
int R,C,T,up=-1;
vvi sol(vvi A){
    vvi ret(R,vector<int>(C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(A[i][j]>0){
                int cnt=0;
                int d = A[i][j]/5;
                for(int k=0;k<4;k++){
                    int ny=i+dy[k],nx=j+dx[k];
                    if(ny<0||nx<0|ny>=R||nx>=C||A[ny][nx]==-1) continue;
                    ret[ny][nx]+=d;
                    cnt++;
                }           
                ret[i][j]+=A[i][j]-cnt*d;
            }
        }
    }
    vvi ret2 = ret;
    for(int i=2;i<C;i++) {
        ret2[up][i] = ret[up][i-1];
        ret2[up+1][i] = ret[up+1][i-1];
    }
    for(int i=C-2;i>=0;i--) {
        ret2[0][i] = ret[0][i+1];
        ret2[R-1][i] = ret[R-1][i+1];
    }
    for(int i=up-1;i>=0;i--) ret2[i][C-1] = ret[i+1][C-1];
    for(int i=1;i<=up;i++) ret2[i][0] = ret[i-1][0];
    for(int i=up+2;i<R;i++) ret2[i][C-1] = ret[i-1][C-1];
    for(int i=R-2;i>=up+1;i--) ret2[i][0] = ret[i+1][0];
    ret2[up][0]=ret2[up+1][0]=-1;
    ret2[up][1]=ret2[up+1][1]=0;
    return ret2;
}
int main(){
    scanf("%d%d%d",&R,&C,&T);

    vvi A(R,vector<int>(C));
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++) {
            scanf("%d",&A[i][j]);
            if(A[i][j]==-1){
                if(up==-1) up=i;
            }
        }

    while(T--) A=sol(A);
    
    int ans=0;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(A[i][j]>0) ans+=A[i][j];

    printf("%d",ans);
}