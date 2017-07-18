//#include <iostream> 
//#include <cstdlib> 
//#include <cstdio> 
//#include <vector> 
//#include <algorithm> 
//using namespace std;
//
//#define inf 987654321
//
//int triangle_no[123], psum[123];
//int dp[300001];
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	triangle_no[1] = psum[1] = 1;
//	int add = 2;
//	for (int i = 2; i <= 122; i++) {
//		triangle_no[i] = triangle_no[i - 1] + add;
//		psum[i] = psum[i - 1] + triangle_no[i];
//		++add;
//	}
//	for (int i = 1; i <= n; i++) {
//		dp[i] = inf;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= 122; j++) {
//			if (psum[j] <= i) {
//				int temp = dp[i - psum[j]];
//				if (temp != inf && temp + 1 < dp[i]) {
//					dp[i] = temp + 1;
//				}
//			}
//		}
//	}
//	printf("%d\n", dp[n]);
//	for (int i = 1; i <= n; i++)
//		printf("%d\n", dp[i]);
//	return 0;
//
//
//}



















#include <stdio.h>

int sum[150],dp[300001];
int main() {
	int N,min,mi=0;
	scanf("%d", &N);
	sum[1] = 1;
	for (int i = 2; i <= 149; i++) {
		sum[i] = sum[i - 1] + (i)*(i+1) / 2;
		if (sum[i] >= 300000) {
			break;
		}
		mi = i - 1;
	}
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		min = dp[i - 1] + 1;
		for (int j = 1;sum[j]<=i ; j++) {
			if(min>  dp[i - sum[j]] + 1)
				min = dp[i - sum[j]] + 1;
		}
		dp[i] = min;
	}
	printf("%d", dp[N]);
		for (int i = 1; i <= N; i++)
			printf("%d\n", dp[i]);
}