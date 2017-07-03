#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int inf = 987654321;

int height[101][101];
int dp[101][101][230];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M, K,ans=inf;
		cin >> N >> M >> K;
	
		for (int i = 0; i <= M; i++) 
			for (int j = 0; j <= N; j++) {
				cin >> height[j][i];
				for (int k = 0; k <= M + N; k++)
					dp[j][i][k] = inf;
		}

		int water, h;
		dp[0][0][0] = 0;
		for (int i = 1; i <= N; i++) {
			water = height[i][0] < 0 ? 1 : 0;
			h = abs(height[i][0]);
			for (int k = 0; k <= M+N; k++) {
				if (dp[i - 1][0][k] != inf) {
					dp[i][0][k + water] = dp[i - 1][0][k] + abs(h - abs(height[i - 1][0]));
				}
			}
		}

		for (int i = 1; i <= M; i++) {
			water = height[0][i] < 0 ? 1 : 0;
			h = abs(height[0][i]);
			for (int k = 0; k <= M+N; k++) {
				if (dp[0][i-1][k] != inf)
					dp[0][i][k + water] = dp[0][i-1][k] + abs(h - abs(height[0][i-1]));
			}
		}

		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				water = height[j][i] < 0 ? 1 : 0;
				h = abs(height[j][i]);
				for (int k = 0; k <= M+N; k++) {
					dp[j][i][k + water] = min(inf,
											min(dp[j][i - 1][k] + abs(h - abs(height[j][i - 1])), 
											  dp[j - 1][i][k] + abs(h - abs(height[j - 1][i])))
											 );
				}
			}
		}

		for (int i = K; i <= M+N; i++) {
			if(dp[N][M][i])
			ans = min(ans, dp[N][M][i]);
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << ans << endl;
	}
	return 0;
}