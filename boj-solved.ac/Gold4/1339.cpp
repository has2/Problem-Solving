#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int N,a[27],ans,cnt;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            int sz = s.size()-j-1;
            int k = 1;
            while(sz--) k*=10;
            a[s[j]-'A'] += k;
        }
    }
    vector<int> v;
    for(int i=0;i<26;i++) if(a[i]) v.push_back(a[i]);
    sort(v.begin(),v.end());
    int j=0;
    for(int i=9-v.size()+1;i<=9;i++) ans += i*v[j++];
    cout << ans;
}


// #include <algorithm>
// #include <vector>
// #include <string>
// #include <iostream>
// #include <set>
// using namespace std;
// int N,cvt[27],ans;
// vector<string> a;
// int main(){
//     set<char> s;
//     scanf("%d",&N);
//     a.resize(N);
//     for(int i=0;i<N;i++){
//         cin >> a[i];
//         for(auto c : a[i]) s.insert(c);
//     }
//     vector<int> v;
//     for(int i=0;i<s.size();i++) v.push_back(9-i);
//     reverse(v.begin(),v.end());
//     do{ 
//         int i=0;
//         for(auto c : s) {
//             cvt[c-'A']=v[i++];
//         }
//         int sum = 0;
//         for(auto str : a){
//             int k=1;
//             for(int j=str.size()-1;j>=0;j--) {
//                 sum+=cvt[str[j]-'A']*k;
//                 k*=10;
//             }
//         }
//         ans = max(ans,sum);
//     }while(next_permutation(v.begin(),v.end()));
//     cout << ans;
// }