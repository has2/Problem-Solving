#include <cstdio>
double A,B,dp[19][19][19];
int k[12] = {0,1,4,6,8,9,10,12,14,15,16,18};
double sol(int cur,int a,int b){
    if(cur<a || cur<b || a<0 || b<0) return 0;
    if(cur==0) return 1;
    
    double& ret = dp[cur][a][b];
    if(ret!=-1.0) return ret;
    ret=0.0;
    ret+=A*B*sol(cur-1,a-1,b-1);
    ret+=(1-A)*B*sol(cur-1,a,b-1);
    ret+=A*(1-B)*sol(cur-1,a-1,b);
    ret+=(1-B)*(1-A)*sol(cur-1,a,b);    
    return ret;
}
int main(){
    scanf("%lf%lf",&A,&B);
    A/=100,B/=100;
    for(int i=0;i<=18;i++)
        for(int j=0;j<=18;j++) 
            for(int k=0;k<=18;k++) dp[i][j][k]=-1.0;


    for(int i=0;i<=18;i++)
        for(int j=0;j<=18;j++) sol(18,i,j);
    
    double ans = 1;    
    for(int i=0;i<12;i++)
        for(int j=0;j<12;j++) ans-=dp[18][k[i]][k[j]];
        
    printf("%.7lf",ans);
}
