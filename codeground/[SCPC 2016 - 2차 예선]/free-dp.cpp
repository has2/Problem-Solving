#include <iostream>
#include <algorithm>

using namespace std;

int P[10001];
int Q[10001];
int dp[10001][4];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int W;
		cin >> W;
		for (int i = 1; i <= W; i++)
			cin >> P[i];
		for (int i = 1; i <= W; i++)
			cin >> Q[i];
		
		dp[1][1] = P[1];
		dp[1][2] = Q[1];
		dp[1][3] = 0;

		for (int i = 2; i <= W; i++) {
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]) + P[i];
			dp[i][2] = dp[i - 1][3] + Q[i];
			dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]);
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << max(dp[W][1], dp[W][2]) << endl;
	}
	return 0;
}