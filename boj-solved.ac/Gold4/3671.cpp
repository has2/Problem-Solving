#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool prime[10000000];
int t;
int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    cin >> t;
    prime[0]=prime[1]=1;
    for(int i=2;i<10000000;i++){
        for(int j=i*2;j<10000000;j+=i){
            prime[j]=1;
        }
    }
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        set<int> st;
        for(int i=1;i<(1<<n);i++){
            string a;
            for(int j=0;j<n;j++){
                if((i&(1<<j))>0) a.push_back(s[j]);
            }
            
            sort(a.begin(),a.end());
            
            do{
                int num = stoi(a);
                if(!prime[num]) st.insert(num);
            }while(next_permutation(a.begin(),a.end()));
        }
        cout << st.size();
    }
}