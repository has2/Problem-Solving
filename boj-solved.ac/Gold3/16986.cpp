#include <cstdio>
int N,K,map[10][10],seq[3][21];
bool use[10];
int sol(int c1,int c2,int r,int k0,int k1,int k2){
    if(k1==K||k2==K) return 0;
    if(k0==K) return 1;
    int a=-1,b;
    for(int i=0;i<3;i++){
        if(r!=i){
            if(a==-1) a=i;
            else b=i;
        }
    }
    int ka,kb,t;
    if(b==1) t=c1;
    else t=c2;
    kb=seq[b][t];
    if(a!=0){
        ka=seq[a][c1];
        if(map[ka][kb] < 2) {
            if(sol(c1+1,c2+1,a,k0,k1,k2+1)) return 1;
        }else{
            if(sol(c1+1,c2+1,b,k0,k1+1,k2)) return 1;
        }
    }else{
        for(int i=1;i<=N;i++){
            if(!use[i]){
                use[i]=1;
                int kk1=k1,kk2=k2,cc1=c1,cc2=c2;
                if(b==1) kk1++, cc1++;
                else kk2++, cc2++;
                                
                if(map[i][kb]<2){
                    if(sol(cc1,cc2,a,k0,kk1,kk2)) return 1;
                }else{
                    if(sol(cc1,cc2,b,k0+1,k1,k2)) return 1;
                }
                use[i]=0;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) scanf("%d",&map[i][j]);
    for(int i=1;i<3;i++) 
        for(int j=0;j<20;j++) scanf("%d",&seq[i][j]);
    printf("%d",sol(0,0,2,0,0,0));
}