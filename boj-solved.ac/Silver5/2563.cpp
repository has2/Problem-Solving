#include <cstdio>
bool c[101][101];
int n,a,b,r;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        for(int i=a+1;i<=a+10;i++)
            for(int j=b+1;j<=b+10;j++)
                if(!c[i][j]) r+=c[i][j]=1;
    }
    printf("%d",r);
}