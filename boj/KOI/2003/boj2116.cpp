//BOJ
//ID : 2116 / Bruteforce
//2017/09/10

#include <cstdio>
#include <algorithm>
int par[7] = { 0,6,4,5,2,3,1 };
int n,dice[10000][7],ret;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= 6; j++)
			scanf("%d", &dice[i][j]);
	
	for (int i = 1; i < 7; i++) {

		int cur = i;
		int sum = 0;

		for (int j = 0; j < n; j++) {
			int maxv = 0;
			for (int k = 1; k < 7; k++) 
				if (k != dice[j][cur] && k != dice[j][par[cur]]) maxv = std::max(maxv, k);
			sum += maxv;

			if (j < n-1) {
				for (int k = 1; k < 7; k++)
					if (dice[j][par[cur]] == dice[j + 1][k]) {
						cur = k;
						break;
					}
			}
		}
		ret = std::max(ret, sum);
	}
	printf("%d", ret);
}



