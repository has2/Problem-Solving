#include <stdio.h>

int main() {
	int N, jump[1000], fin = 0, cnt = 0;
	int dp[1000];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &jump[i]);

	if (N == 1) {
		printf("0");
		return 0;
	}

	if (jump[0] == 0) {
		printf("-1");
		return 0;
	}

	//if()

	dp[cnt] = 0;

	while (cnt<=N) {
		int max = 0, max_index = 0, check=0;
		for (int j = 1; j <= jump[dp[cnt]]; j++) {
			if (dp[cnt] + j == N - 1) {
				fin = 1; cnt++;
				break;
			}
			check += jump[dp[cnt] + j];
			if (j == jump[dp[cnt]] && check == 0) {
				printf("-1\n");
				return 0;
			}
		
			if (max < j + jump[dp[cnt] + j]) {
				max = j + jump[dp[cnt] + j]; max_index = j;
			}
		}
		if (fin == 1)
			break;

		dp[cnt + 1] = dp[cnt] + max_index;
		cnt++;
	
	}
	
	printf("%d\n", cnt);
}