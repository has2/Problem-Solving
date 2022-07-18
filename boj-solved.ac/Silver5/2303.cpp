#include <cstdio>
#include <string>
int N,a[5],mv,mi;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int sum=0;
        for(int j=0;j<5;j++) {
            scanf("%d",&a[j]);
            sum+=a[j];
        }
        for(int j=0;j<4;j++){
            for(int k=j+1;k<5;k++){
                int s = sum-a[j]-a[k];
                if(s%10>=mv){
                    mv=s%10;
                    mi=i;
                }
            }
        }
    }
    printf("%d",mi+1);
}