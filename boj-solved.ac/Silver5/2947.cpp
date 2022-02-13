#include <cstdio>
int a[5];
void prt(){
    for(int i=0;i<5;i++) printf("%d ",a[i]);
    puts("");
}
bool cmp(int i,int j){
    if(a[i]>a[j]){
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
        return true;
    }
    return false;
}
int main(){
    for(int i=0;i<5;i++) scanf("%d",&a[i]);
    while(1){
        bool ok=0;
        for(int i=0;i<4;i++){
            if(cmp(i,i+1)) {
                ok=1;
                prt();
            }
        }
        if(!ok) break;
    }
}