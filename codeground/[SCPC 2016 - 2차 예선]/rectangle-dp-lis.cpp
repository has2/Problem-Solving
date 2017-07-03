#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct rec {
	int xl, yl, xr, yr;
	rec(){}
	rec(int xl,int yl,int xr,int yr) : xl(xl),yl(yl),xr(xr),yr(yr){}
};

int dp[5001];
rec Recarr[5001];
int N, M, K, a, b, c, d;

void getCount(int k) {

	dp[k] = 1;
	for (int i = 1; i <= K; i++) 
		if (i != k && Recarr[k].xl < Recarr[i].xl && Recarr[k].yl < Recarr[i].yl
			&& Recarr[k].xr > Recarr[i].xr && Recarr[k].yr > Recarr[i].yr) {
			if (dp[i] == 0)
				getCount(i);
			dp[k] = max(dp[i] + 1, dp[k]);
		}
}


int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N >> M >> K;
		int ans = -1;
		for (int i = 1; i <= K; i++) {
			cin >> a >> b >> c >> d;
			Recarr[i] = rec(a, b, c, d);
		}
		
		for (int i = 1; i <= K; i++) 
			if(dp[i] ==0)
				getCount(i);
		
		for (int i = 1; i <= K; i++)
			ans = max(dp[i], ans);
		cout << "Case #" << test_case + 1 << endl;
		cout << ans << endl;
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}