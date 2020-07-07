#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

	int dp[500000];

	int sol(int k) {

		if (k == 1) return 0;

		int& ret = dp[k];
		if (ret != 0) return ret;

		if (k % 2) ret = 1 + sol(3 * k + 1);
		else ret = 1 + sol(k/2);
		
		return ret;
	}

	int getKth(int lo, int hi, int k) {
		vector<pair<int,int>> a;
		for (int i = lo; i <= hi; i++) a.push_back(make_pair(sol(i),i));
		
		sort(a.begin(), a.end());
	
		return a[k-1].second;
	}
};